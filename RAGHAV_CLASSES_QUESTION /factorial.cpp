#include<iostream>
using namespace std;
int factorial(int x)
{
    if(x==1) return 1;
    return x*factorial(x-1);
}
int main()
{
    int x;
    cout<<"enter your no.";
    cin>>x;
    int ans=factorial(x);
    cout<<"your ans is "<<ans;
    return 0;
}