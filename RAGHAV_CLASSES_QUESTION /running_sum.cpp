#include<iostream>
#include<vector>
using namespace std;
void findans(vector<int>&v,int arr[],int n)
{
    v.push_back(arr[0]);
    for (int i=1;i<n;i++)
    {
        int ch=v[v.size()-1];
        v.push_back(arr[i]+ch);
    }
}
int main()
{
    int arr[]={1,4,5,3,2,7,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v;
    findans(v,arr,n);
    for (int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}