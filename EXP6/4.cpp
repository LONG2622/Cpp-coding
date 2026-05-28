#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Student { int id, score; };
const int N = 30;

void printHigh(Student s[]) {
    cout << "85+:\n学号 成绩\n";
    for (int i = 0; i < N; i++)
        if (s[i].score > 85) cout << s[i].id << " " << s[i].score << "\n";
}

void printLow(Student s[]) {
    cout << "60-:\n学号 成绩\n";
    for (int i = 0; i < N; i++)
        if (s[i].score < 60) cout << s[i].id << " " << s[i].score << "\n";
}

int countAvg(Student s[]) {
    int sum = 0;
    for (int i = 0; i < N; sum += s[i++].score);
    double avg = sum / 30.0;
    cout << "平均分:" << avg << "\n";
    int cnt = 0;
    for (int i = 0; i < N; cnt += (s[i++].score >= avg));
    return cnt;
}

void sortDesc(Student s[]) {
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (s[j].score < s[j + 1].score) swap(s[j], s[j + 1]);
    cout << "排序后:\n学号 成绩\n";
    for (int i = 0; i < N; i++) cout << s[i].id << " " << s[i].score << "\n";
}

int main() {
    srand(time(0));
    Student s[N];
    for (int i = 0; i < N; i++) { s[i].id = i + 1; s[i].score = rand() % 51 + 50; }
    printHigh(s);
    printLow(s);
    cout << "≥平均分人数:" << countAvg(s) << "\n";
    sortDesc(s);
    return 0;
}