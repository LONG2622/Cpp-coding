#include <iostream>
using namespace std;
int main() {
    char c;
    int count[5]={0};
    int n=0;
    cout<<"Enter characters. Type '#' to stop:\n";
    while (cin >> c && c != '#')
    {
        switch(c)
        {
            case'a':count[0]++;
            break;
            case'e':count[1]++;
            break;
            case'i':count[2]++;
            break;
            case'o':count[3]++;
            break;
            case'u':count[4]++;
            break;
            case'A':count[0]++;
            break;
            case'E':count[1]++;
            break;
            case'I':count[2]++;
            break;
            case'O':count[3]++;
            break;
            case'U':count[4]++;
            break;
        }}
        for(int i=0;i<5;i++)
        {
            n+=count[i];
        }
        cout<<"a/A的个数为："<<count[0]<<endl;
        cout<<"e/E的个数为："<<count[1]<<endl;
        cout<<"i/I的个数为："<<count[2]<<endl;
        cout<<"o/O的个数为："<<count[3]<<endl;
        cout<<"u/U的个数为："<<count[4]<<endl;
        cout<<"总个数为："<<n<<endl;
        return 0;
}

