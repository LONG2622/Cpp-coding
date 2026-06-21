#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream fout("D:\\output.txt");
    fout << "This is a log message." << endl;
    fout.close();

    int a=10;
    int b=20;
    cout<<"The sum of a and b is: "<<a+b<<endl;
    clog << "The log of a and b is: " << a + b << endl;
    return 0;
}