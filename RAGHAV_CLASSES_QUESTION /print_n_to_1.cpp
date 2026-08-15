#include<iostream>
using namespace std;
void printing(int n)
{

    cout<<n;
    if (n==1) return; 
    printing(n-1);
}
int main()
{
    int n=6;
    printing(n);
    return 0;
}