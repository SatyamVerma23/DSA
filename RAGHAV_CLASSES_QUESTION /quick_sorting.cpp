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
        if(arr[j]>arr[pivotindex]) j++;
        else if(arr[i]>arr[pivotindex] && arr[j]<=arr[pivotindex])
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivotindex;
}
void quicksorting(int arr[],int si,int ei)
{
    if(si>=ei) return;
    int pi=partition(arr,si,ei);
    quicksorting(arr,0,pi-1);
    quicksorting(arr,pi+1,ei);
}
int main()
{
    int arr[]={5,1,8,2,7,6,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    quicksorting(arr,0,n-1);
    cout<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}