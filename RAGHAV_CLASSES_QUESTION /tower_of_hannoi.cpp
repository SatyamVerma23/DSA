#include<iostream>
using namespace std;
void hannoi(int n,char a,char b,char c)
{
    if(n==0) return ;
    hannoi(n-1,a,c,b);
    cout<<a<<" -> "<<c<<endl;
    hannoi(n-1,b,a,c);
}
int main()
{
    int n=3;
    hannoi(n,'A','B','C');
    return 0;
}