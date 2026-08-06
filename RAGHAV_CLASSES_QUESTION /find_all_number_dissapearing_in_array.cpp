#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int main()
{
    int arr[]={4,3,2,7,8,2,3,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0;
    while(i<n)
    {
        int ci=arr[i]-1;
        if(arr[i]==arr[ci]) i++;
        else if(arr[i]==i+1 || ci==i)
        {
            i++;
        }
        else
        {
            swap(arr[i],arr[ci]);
        }
    }
    vector<int>v;
    int j=0;
    while(j<n)
    {
        if(arr[j]==j+1) j++;
        else
        {
            v.push_back(j+1);
            j++;
        }
    }
    int n2=v.size();
    for (int i=0;i<n2;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}