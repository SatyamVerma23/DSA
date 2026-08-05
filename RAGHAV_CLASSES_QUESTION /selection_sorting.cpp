#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    int n;
    cout<<"enetr size of array"<<endl;
    cin>>n;
    vector<int>v(n);
    for (int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<v[i];
    }
    cout<<endl;
    for (int i=0;i<n-1;i++)
    {
        int mn=INT_MAX;
        int idx=-1;
        for (int j=i;j<n;j++)
        {
            if(mn>v[j])
            {
                mn=v[j];
                idx=j;
            }
        }
        swap(v[i],v[idx]);
    }
    cout<<"your sorted array will be"<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<v[i];
    }
    return 0;
}