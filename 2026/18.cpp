#include<iostream>
using namespace std;
struct Student{
    string name;
    int age;
    int score;
};
Student train(Student s) {
    s.age += 1;
    s.score = s.score * 6 / 5;
    if (s.score > 600) {
        s.score = 600;
    }   
    return s;
}
int main() {
    int n;
    cin >> n;
    Student stu[105];
    for (int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].age >> stu[i].score;
        stu[i] = train(stu[i]); 
    }
    for (int i = 0; i < n; i++) {
        cout << stu[i].name << " " 
             << stu[i].age << " " 
             << stu[i].score << endl;
    }
    return 0;
}