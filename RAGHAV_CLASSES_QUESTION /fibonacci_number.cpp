#include<iostream>
using namespace std;
int fibbo(int a,int b,int n)
{
    int r=a+b;
    if(n==0) return r;
    n--;
    return fibbo(b,r,n);
}
int main()
{
    int n;
    cout<<"which term you want to know";
    cin>>n;
    cout<<endl;
    int a=1;
    int b=1;
    int ans=fibbo(a,b,n-2);
    cout<<"your ans is "<<ans;
    return 0;
}