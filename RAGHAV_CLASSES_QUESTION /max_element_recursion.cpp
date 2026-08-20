#include<iostream>
#include<climits>
using namespace std;
int maxelements(int arr[],int n,int idx)
{
    if(idx==n) return INT_MIN;
    return max(arr[idx],maxelements(arr,n,idx+1));
}
int main()
{
    int arr[]={2,1,6,9};
    cout<<maxelements(arr,4,0);
    return 0;
}