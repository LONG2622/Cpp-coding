#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
bool isVowel(char c, int idx) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return (c == 'y' && idx != 0);
}

void pigLatin(char s[], char res[]) {
    int len = strlen(s);
    int resIdx = 0;
    
    // 步骤1：转换为小写，存入res临时存储
    for (int i = 0; i < len; i++) {
        res[resIdx++] = tolower(s[i]);
    }
    res[resIdx] = '\0';
    len = resIdx; // 更新长度（实际未变，仅统一变量）
    
    // 步骤2：按规则处理
    if (isVowel(res[0], 0)) {
        // 规则2：结尾加hay
        strcat(res, "hay");
    } else if (len >= 2 && res[0] == 'q' && res[1] == 'u') {
        // 规则3：qu移到末尾加ay
        char temp[1000];
        // 复制qu之后的字符
        int tempIdx = 0;
        for (int i = 2; i < len; i++) {
            temp[tempIdx++] = res[i];
        }
        // 拼接qu和ay
        temp[tempIdx++] = 'q';
        temp[tempIdx++] = 'u';
        temp[tempIdx++] = 'a';
        temp[tempIdx++] = 'y';
        temp[tempIdx] = '\0';
        strcpy(res, temp);
    } else {
        // 规则4：连续辅音移到末尾加ay
        int consonantEnd = 0;
        while (consonantEnd < len && !isVowel(res[consonantEnd], consonantEnd)) {
            consonantEnd++;
        }
        char temp[1000];
        int tempIdx = 0;
        // 复制辅音后的字符
        for (int i = consonantEnd; i < len; i++) {
            temp[tempIdx++] = res[i];
        }
        // 复制连续辅音
        for (int i = 0; i < consonantEnd; i++) {
            temp[tempIdx++] = res[i];
        }
        // 加ay
        temp[tempIdx++] = 'a';
        temp[tempIdx++] = 'y';
        temp[tempIdx] = '\0';
        strcpy(res, temp);
    }
}
int main() {
    char s[1000], res[1000];
    cin >> s;
    pigLatin(s, res);
    cout << res << endl;
    return 0;
}