#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int arr[]={7,1,2,5,8,4,9,3,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=4;
    int prevsum=0;
    for (int i=0;i<k;i++)
    {
        prevsum+=arr[i];
    }
    int i=1;//i start with this i=1 not from i=0 bcoz at starting before while loop we calculate prevsum now we have to start with i=1
    int j=k;
    int maxsubarray=prevsum;
    int idx=0; 
    while(j<n)
    {
        int currentsum=prevsum+arr[j]-arr[i-1];
        if(maxsubarray<currentsum)
        {
            maxsubarray=currentsum;
            idx=i;
        }
        prevsum=currentsum;
        i++;
        j++;
    }
    cout<<"max subarray is "<<maxsubarray<<"at idx "<<idx;
    return 0;
}