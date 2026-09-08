#include<iostream>
#include<algorithm>   // FIX
#include<climits>     // FIX
using namespace std;
int main()
{
    int arr[]={-1,-8,0,5,-9};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+n);
    int suffixarray[n];
    suffixarray[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        suffixarray[i]=suffixarray[i+1]+arr[i];
    }
    int idx=-1;
    for (int i=0;i<n;i++)
    {
        if(suffixarray[i]>0) 
        {
            idx=i;
            break;
        }
    }
    int ans=0;
    int nw[n-idx];
    for (int i=0;i<n-idx;i++)
    {
        nw[i]=arr[i+idx];
    }
    for (int i=0;i<n-idx;i++)
    {
        ans=ans+nw[i]*(i+1);
    }
    cout<<"your final ans is "<<ans;
    return 0;
}