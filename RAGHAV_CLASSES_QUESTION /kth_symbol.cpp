#include<iostream>
#include<vector>
using namespace std;
int print(int n,int k)
{
    if(n==1)
    {
        return 0;
    }
    if(k%2==0)
    {
        int ans=print(n-1,k/2);
        if(ans==0) return 1;
        else return 0;
    }
    else //odd
    {
        int ans=print(n-1,(k/2)+1);
        return ans;
    }
}
int main()
{
    int n=4,k=7;
    cout<<"your ans is "<<print(n,k);
    return 0;
}