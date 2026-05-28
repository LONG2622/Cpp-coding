/*#include <iostream>
using namespace std;
long fact(int n) //递归函数
{ long h;
  if(n>0) h=n*fact(n-1);
  else h=1;
  return h;
} 
int main(){
 int n;
  cout<<"输入正整数n:";
  cin>>n;
  cout<<"n!="<<fact(n)<<endl;
}*/
/*#include <iostream>
using namespace std;
long f(int n) //递归函数
{ long h;
  if(n>2)    h=f(n-1)+f(n-2);
  else         h=1;
  return h;
} 
int main()
{
      cout<<f(10)<<" "<<endl;
}*/
#include <iostream>
using namespace std;

long fib(int n) // 迭代版斐波那契，无重复计算
{
    if (n <= 2)
        return 1;
    long a = 1, b = 1, res; // a=f(n-2), b=f(n-1), res=f(n)
    for (int i = 3; i <= n; i++)
    {
        res = a + b;
        a = b;       
        b = res;    
    }
    return res;
}

int main()
{
    cout << fib(10) << endl; // 输出：55
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

vector<long> memo; // 缓存已计算的结果，避免重复计算

long fib(int n)
{
    if (n <= 2)
        return 1;
    if (memo[n] != 0) // 若已计算过，直接返回缓存值
        return memo[n];
    memo[n] = fib(n-1) + fib(n-2); // 计算并缓存
    return memo[n];
}

int main()
{
    int n = 10;
    memo.resize(n+1, 0); // 初始化缓存数组（大小n+1，初始值0）
    cout << fib(10) << endl; // 输出：55
    return 0;
}