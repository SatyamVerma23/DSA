#include<iostream>
using namespace std;
void findinghcf(int devisor,int divident)
{
    int r=divident%devisor;
    if(r==0)
    {
        cout<<devisor;
    }
    else
    {
        findinghcf(r,devisor);
    }
}
int main()
{
    int a=24,b=60;
    int devisor=min(a,b);
    int divident=max(a,b);
    findinghcf(devisor,divident);
    return 0;
}