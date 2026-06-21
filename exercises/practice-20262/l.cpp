#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 30;// 最大地图尺寸
int mineMap[MAX_SIZE][MAX_SIZE];// 是否翻开
bool isReveal[MAX_SIZE][MAX_SIZE];// 是否翻开
bool isFlag[MAX_SIZE][MAX_SIZE];// 是否插旗
int rows, cols, mineNum;

void initMap() {// 初始化地图
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mineMap[i][j] = 0;
            isReveal[i][j] = false;
            isFlag[i][j] = false;
        }// 初始化地图，所有格子初始为0（无地雷），未翻开，未插旗
    }
        srand(time(0)); // 随机数种子
    int count = 0;
    while (count < mineNum) {
        int r = rand() % rows;
        int c = rand() % cols;
        if (mineMap[r][c] != -1) {
            mineMap[r][c] = -1;
            count++;
            for (int dr = -1; dr <= 1; dr++) { // 更新周围8个格子的数字
                for (int dc = -1; dc <= 1; dc++) {
                    if (dr == 0 && dc == 0) continue;
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                        if (mineMap[nr][nc] != -1) {
                            mineMap[nr][nc]++;
                        }
                    }
                }
            }
        }
    }
}
// 打印地图
void printMap() {
    system("cls"); // Windows清屏
    cout << "====== game ======" << endl;
    cout << "  ";
    for (int j = 0; j < cols; j++) {
        cout << setw(2) << j;
    }
    cout << endl;

    for (int i = 0; i < rows; i++) {
        cout << setw(2) << i;
        for (int j = 0; j < cols; j++) {
            if (isFlag[i][j]) {
                cout << " F"; // 旗帜
            } else if (!isReveal[i][j]) {
                cout << " U"; // 未翻开
            } else {
                if (mineMap[i][j] == -1) {
                    cout << " *"; // 地雷
                } else if (mineMap[i][j] == 0) {
                    cout << "  "; // 空白
                } else {
                    cout << " " << mineMap[i][j];
                }
            }
        }
        cout << endl;
    }
    cout << "======================" << endl;
    cout << "input :raw col operate(0=unreveal,1=flag)" << endl;
}
// 翻开格子（递归扩展空白）
void reveal(int x, int y) {
    if (x < 0 || x >= rows || y < 0 || y >= cols) return;
    if (isReveal[x][y] || isFlag[x][y]) return;
    isReveal[x][y] = true;
    // 踩到地雷
    if (mineMap[x][y] == -1) {
        printMap();
        cout << "====== Game Over! You hit a mine! ======" << endl;
        exit(0);
    }

    // 空白格自动扩散
    if (mineMap[x][y] == 0) {
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                reveal(x + dx, y + dy);
            }
        }
    }
}

// 判断胜利
bool checkWin() {
    int cnt = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mineMap[i][j] != -1 && isReveal[i][j]) {
                cnt++;
            }
        }
    }
    return cnt == rows * cols - mineNum;
}

int main() {
    cout << "int put :raw col mineNum：";
    cin >> rows >> cols >> mineNum;

    // 简单合法性检查
    if (rows < 1 || cols < 1 || mineNum < 1 || mineNum >= rows * cols) {
        cout << "Input is invalid!" << endl;
        return 1;
    }
    initMap();

    while (true) {
        printMap();

        int x, y, op;
        cin >> x >> y >> op;

        if (op == 1) {   // 插旗 / 取消旗
            if (!isReveal[x][y]) {
                isFlag[x][y] = !isFlag[x][y];
            }
        } else { // 翻开
            reveal(x, y);
        }
        // 判断胜利
        if (checkWin()) {
            printMap();
            cout << "====== You Win! ======" << endl;
            break;
        }
    }
    return 0;
}