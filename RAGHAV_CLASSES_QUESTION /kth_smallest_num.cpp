#include<iostream>
#include<climits>
using namespace std;
int partition(int arr[],int si,int ei)
{
    int count=0;
    int pivotele=arr[si];
    for (int i=si+1;i<=ei;i++)
    {
        if(arr[i]<=pivotele) count++;
    }
    int pivotindex=count+si;
    swap(arr[si],arr[pivotindex]);
    int i=si,j=ei;
    while(i<pivotindex && j>pivotindex)
    {
        if(arr[i]<=arr[pivotindex]) i++;
        if(arr[j]>arr[pivotindex]) j--;
        else if(arr[i]>arr[pivotindex] && arr[j]<=arr[pivotindex])
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivotindex;
}
int quicksorting(int arr[],int si,int ei,int k)
{
    if(si>=ei) return arr[si];
    int pi=partition(arr,si,ei);
    if(pi+1==k) return arr[pi];
    else if(pi+1<k)
    {
    return quicksorting(arr,pi+1,ei,k);
    }
    else
    {
    return quicksorting(arr,0,pi-1,k);
    }
}
int main()
{
    int arr[]={5,1,-8,2,7,6,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=4;
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    int ans=quicksorting(arr,0,n-1,k);
    cout<<"ans is"<<ans;
    return 0;
}