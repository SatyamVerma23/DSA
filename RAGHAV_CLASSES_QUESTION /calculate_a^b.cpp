#include<iostream>
using namespace std;
int power(int a,int b)
{
    if(b==1) return a;
    return (a*power(a,b-1));
}
int main()
{
    int a;
    cout<<"enter your number"<<" ";
    cin>>a;
    int b;
    cout<<"enter your power"<<" ";
    cin>>b;
    int x=power(a,b);
    cout<<"your ans is "<<x;
    
    return 0;
}