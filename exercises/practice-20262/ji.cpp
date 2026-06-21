#include "gd32f4xx.h"
#include "main.h"
#include "i2c.h"
#include "systick.h"

i2c_addr_def key_addr; 
i2c_addr_def e1_addr;  

uint8_t keyvalue[6]; 

const uint8_t DIG_NUM_CODE[16] = {
    0x3F, 0x06, 0x5B, 0x4F,
    0x66, 0x6D, 0x7D, 0x07,
    0x7F, 0x6F, 0x77, 0x7C,
    0x39, 0x5E, 0x79, 0x71
};

// ================= 计算器全局变量 =================
int calc_step = 0;        // 0:输入第1个数  1:输入运算符  2:输入第2个数
int num1 = 0;            // 第一个数
int num2 = 0;            // 第二个数
int op = 0;              // 10=+(*)  11=-(#)
int last_key = -1;       // 上一次按键（边沿检测用）

// ================ 显示一位数字 ================
void show_one_digit(uint32_t i2c_periph, uint8_t i2c_addr, uint8_t reg, uint8_t hex_num)
{
    if (hex_num > 0x0F) return;
    i2c_byte_write(i2c_periph, i2c_addr, reg, DIG_NUM_CODE[hex_num]);
}

// ================ 清空4位数码管 ================
void clear_display(void) {
    i2c_byte_write(e1_addr.periph, e1_addr.addr, 0x96, 0x00);
    i2c_byte_write(e1_addr.periph, e1_addr.addr, 0x97, 0x00);
    i2c_byte_write(e1_addr.periph, e1_addr.addr, 0x98, 0x00);
    i2c_byte_write(e1_addr.periph, e1_addr.addr, 0x99, 0x00);
}

// ================ 显示结果（支持负数/两位数） ================
void show_result(int res) {
    clear_display();
    
    if (res < 0) {
        // 显示负数：第一位 = 负号，第二位 = 数字
        i2c_byte_write(e1_addr.periph, e1_addr.addr, 0x96, 0x40);
        show_one_digit(e1_addr.periph, e1_addr.addr, 0x97, -res);
    } 
    else if (res > 9) {
        // 两位数：十位 + 个位
        show_one_digit(e1_addr.periph, e1_addr.addr, 0x96, res / 10);
        show_one_digit(e1_addr.periph, e1_addr.addr, 0x97, res % 10);
    } 
    else {
        // 一位数
        show_one_digit(e1_addr.periph, e1_addr.addr, 0x96, res);
    }
}

// ================ 按键解码函数 ================
int key_trans(void) {
    if(keyvalue[0] & 0x01) return 1;
    if(keyvalue[0] & 0x02) return 4;
    if(keyvalue[0] & 0x04) return 7;
    if(keyvalue[0] & 0x08) return 10;   // * = 加法

    if(keyvalue[2] & 0x01) return 2;
    if(keyvalue[2] & 0x02) return 5;
    if(keyvalue[2] & 0x04) return 8;
    if(keyvalue[2] & 0x08) return 0;    // 0

    if(keyvalue[4] & 0x01) return 3;
    if(keyvalue[4] & 0x02) return 6;
    if(keyvalue[4] & 0x04) return 9;
    if(keyvalue[4] & 0x08) return 11;   // # = 减法

    return -1; // 无按键
}

// ================ I2C设备地址搜索 ================
void i2c_addr_init(void) {
    int i;
    // 搜索按键板
    for (i=0; i<4; i++) {
        if (i2c_addr_poll(I2C0, 0xE8+i*2)) { 
            key_addr.periph=I2C0; 
            key_addr.addr=0xE8+i*2; 
            key_addr.flag=1; 
            break; 
        }
    }
    if (!key_addr.flag) {
        for (i=0; i<4; i++) {
            if (i2c_addr_poll(I2C1, 0xE8+i*2)) { 
                key_addr.periph=I2C1; 
                key_addr.addr=0xE8+i*2; 
                key_addr.flag=1; 
                break; 
            }
        }
    }
    if (key_addr.flag) 
        i2c_cmd_write(key_addr.periph, key_addr.addr, 0x21);

    // 搜索数码管
    for (i=0; i<4; i++) {
        if (i2c_addr_poll(I2C0, 0xE0+i*2)) { 
            e1_addr.periph=I2C0; 
            e1_addr.addr=0xE0+i*2; 
            e1_addr.flag=1; 
            break; 
        }
    }
    if (!e1_addr.flag) {
        for (i=0; i<4; i++) {
            if (i2c_addr_poll(I2C1, 0xE0+i*2)) { 
                e1_addr.periph=I2C1; 
                e1_addr.addr=0xE0+i*2; 
                e1_addr.flag=1; 
                break; 
            }
        }
    }
}

// ===================== 主函数 =====================
int main(void){
    i2c0_gpio_config(); 
    i2c0_config();
    i2c1_gpio_config(); 
    i2c1_config();
    systick_config();
    i2c_addr_init();
    
    if (e1_addr.flag) 
        clear_display();
    
    while(1)
    {
        if(key_addr.flag && e1_addr.flag) 
        {
            // 读取按键寄存器
            i2c_read(key_addr.periph, key_addr.addr, 0x40, keyvalue, 6);
            int current_key = key_trans();
            
            // ===================== 边沿检测：只响应按下瞬间 =====================
            if (current_key != -1 && current_key != last_key) 
            {
                if (calc_step == 0)   // 输入第一个数
                {
                    if (current_key >=0 && current_key <=9)
                    {
                        num1 = current_key;
                        clear_display();
                        show_one_digit(e1_addr.periph, e1_addr.addr, 0x96, num1);
                        calc_step = 1;
                    }
                }
                else if (calc_step == 1)   // 输入运算符 + 或 -
                {
                    if (current_key ==10 || current_key ==11)
                    {
                        op = current_key;
                        clear_display();
                        calc_step = 2;
                    }
                    // 输错可重新输入数字
                    else if (current_key >=0 && current_key <=9)
                    {
                        num1 = current_key;
                        clear_display();
                        show_one_digit(e1_addr.periph, e1_addr.addr, 0x96, num1);
                    }
                }
                else if (calc_step == 2)   // 输入第二个数 + 计算
                {
                    if (current_key >=0 && current_key <=9)
                    {
                        num2 = current_key;
                        int result = 0;
                        
                        if(op ==10)        // 加法
                            result = num1 + num2;
                        
                        if(op ==11)        // 减法：使用补码实现！
                            result = num1 + (~num2 + 1);
                        
                        show_result(result);
                        calc_step = 0;     // 计算完成，回到初始状态
                    }
                }
            }
            last_key = current_key;
        }
        delay_1ms(50);
    }
}