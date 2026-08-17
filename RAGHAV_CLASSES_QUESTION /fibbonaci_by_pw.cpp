#include<iostream>
using namespace std;
int fibbo(int n)
{
    if (n==1 || n==2) return 1;
    return fibbo(n-1)+fibbo(n-2);
}
int main()
{
    int n;
    cout<<"which term ";
    cin>>n;
    cout<<endl;
    // int a=1,b=1;
    int x=fibbo(n);
    cout<<"your ans is "<<x;
    return 0;
}