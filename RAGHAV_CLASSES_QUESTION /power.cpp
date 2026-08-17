#include<iostream>
using namespace std;
int power(int x,int n)
{
    if(n==0) return 1;
    if(n==1) return x;
    int a=power(x,n/2);
    if(n%2==0) return a*a;
    else return a*a*x;
}
int main()
{
    int x=3,n=2;
    int ans=power(x,n);
    cout<<ans;
    return 0;
}