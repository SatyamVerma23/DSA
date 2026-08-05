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
    for (int i=1;i<n;i++)
    {
        int j=i;
        while(j>=0 && v[j]<v[j-1])
        {
            swap(v[j],v[j-1]);
            j--;
        }
    }
    cout<<"your sorted array will be"<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<v[i];
    }
    return 0;

}