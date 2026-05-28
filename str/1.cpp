/*int index(string S,string T,int pos){
    if(pos>0){
        n=strlen(S);m=strlength(T);i=pos;
        while(i<n-m+1){
            substring(sub,S,i,m);
            if(strcompare(sub,T)!=0) ++i;
        else return i;
           }
    }
    return 0;
}*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 截取子串：从S的第i位（从1开始）截取长度为m的子串到sub
void substring(char *sub, const char *S, int i, int m) {
    // 转换为C语言的0索引
    int start = i - 1;
    strncpy(sub, S + start, m);
    // 手动添加字符串结束符
    sub[m] = '\0';
}

// 字符串比较：等价于strcmp，返回0表示相等
int strcompare(const char *a, const char *b) {
    return strcmp(a, b);
}

/**
 * 字符串匹配函数（模拟index功能）
 * @param S 主串（char*）
 * @param T 模式串（char*）
 * @param pos 起始匹配位置（从1开始）
 * @return 匹配成功返回首次出现的位置（从1开始），失败返回0
 */
int index(const char *S, const char *T, int pos) {
    // 1. 异常处理：空串、pos非法、模式串比主串长
    int n = strlen(S);
    int m = strlen(T);
    if (pos < 1 || pos > n || m == 0 || m > n) {
        return 0;
    }

    // 2. 初始化变量（C语言需先声明）
    // 转换为0索引
    int i = pos - 1;
    // 存储截取的子串
    char *sub = (char *)malloc((m + 1) * sizeof(char));
    if (sub == NULL) {
        return 0;
    }

    // 3. 核心匹配逻辑
    // 0索引下，i的最大取值为n-m（保证剩余长度≥m）
    while (i <= n - m) {
        // 截取子串（转换回1索引传给substring）
        substring(sub, S, i + 1, m);
        if (strcompare(sub, T) == 0) {
            free(sub);
            // 返回1索引的位置
            return i + 1;
        }
        // 不匹配则后移
        i++;
    }

    // 4. 匹配失败
    free(sub);
    return 0;
}

// 测试示例
int main() {
    char S[] = "abcdefghijk";
    char T1[] = "def";
    char T2[] = "xyz";
    
    // 从位置1开始匹配"def"
    int res1 = index(S, T1, 1);
    printf("匹配\"def\"的位置：%d\n", res1);  // 输出4
    
    // 从位置5开始匹配"def"
    int res2 = index(S, T1, 5);
    printf("从位置5匹配\"def\"：%d\n", res2);  // 输出0
    
    // 匹配不存在的"xyz"
    int res3 = index(S, T2, 1);
    printf("匹配\"xyz\"的位置：%d\n", res3);  // 输出0
    
    return 0;
}