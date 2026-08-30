#include<iostream>
#include<vector>
using namespace std;
void subarray(vector<int>v,int arr[],int n,int idx)
{
    if(idx==n)
    {
        for (int i=0;i<v.size();i++)
        {
            cout<<v[i];
        }
        cout<<endl;
        return ;
    }
    subarray(v,arr,n,idx+1);
    if(v.size()==0) //copy mein dekho at the starting when v has no element (targeting to a particual situation)
    {
        v.push_back(arr[idx]);
        subarray(v,arr,n,idx+1);
    }
    else if(v[v.size()-1]==arr[idx-1]) //if last element of v and second last element of arr is same then do
    {
        v.push_back(arr[idx]);
        subarray(v,arr,n,idx+1);
    }
}
int main()
{
    int arr[]={1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v;
    subarray(v,arr,n,0);
}