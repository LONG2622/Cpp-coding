#include <iostream>
#include <cstring>
using namespace std;

#define MAX_STR_LEN 100
#define MAX_COMBO_LEN 20

// 去重：输入字符数组s，输出去重后的字符数组unique，返回去重长度
int deduplicate(char s[], char unique[]) {
    int used[256] = {0};
    int len = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char c = s[i];
        if (used[c] == 0) {
            used[c] = 1;
            unique[len++] = c;
        }
    }
    unique[len] = '\0';
    return len;
}

// 生成组合：current数组存储当前组合（每元素对应一个字符）
void generateCombos(char unique[], int uniqueLen, int n, char current[], int pos, int start) {
    if (pos == n) {
        current[pos] = '\0';
        cout << current << " ";
        return;
    }
    for (int i = start; i < uniqueLen; i++) {
        current[pos] = unique[i];  // 数组元素对应组合的一个字符
        generateCombos(unique, uniqueLen, n, current, pos + 1, i);
    }
}

int main() {
    char s[MAX_STR_LEN], unique[MAX_STR_LEN];
    char current[MAX_COMBO_LEN];  // 存储组合的数组（每元素对应一个字符）
    int n, uniqueLen;
    
    cout << "请输入字符串：";
    cin >> s;
    cout << "请输入整数n：";
    cin >> n;
    
    uniqueLen = deduplicate(s, unique);
    cout << "生成的字符组合：" << endl;
    generateCombos(unique, uniqueLen, n, current, 0, 0);
    cout << endl;
    
    return 0;
}