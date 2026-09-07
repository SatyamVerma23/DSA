#include<iostream>
using namespace std;
int main()
{
    int arr[]={1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int prefix[n];
    prefix[0]=1;
    int suffix[n];
    suffix[n-1]=1;
    for (int i=1;i<n;i++)
    {
        prefix[i]=arr[i-1]*prefix[i-1];
    }
    for (int i=n-2;i>=0;i--)
    {
        suffix[i]=arr[i+1]*suffix[i+1];
    }
    int ans[n];
    for (int i=0;i<n;i++)
    {
        ans[i]=prefix[i]*suffix[i];
    }
    for (int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}