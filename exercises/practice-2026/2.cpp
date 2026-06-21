#include<iostream>
#include<fstream>
using namespace std;
int main(){
    char buf[100]={0};
    ifstream file("D:\\output.txt");
    while(file >> buf){
        cout << buf << endl;
    }
}