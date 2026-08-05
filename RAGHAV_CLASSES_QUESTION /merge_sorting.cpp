#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void merging(vector<int>&a,vector<int>&b,vector<int>&v)
{
    int i=0,j=0,k=0;
    while(i<a.size() && j<b.size())
    {
        if(a[i]<b[j])
        {
            v[k]=a[i];
            k++;
            i++;
        }
        else
        {
            v[k]=b[j];
            k++;
            j++;
        }
    }
    if(i==a.size())
    {
        while(j<b.size())
        {
            v[k]=b[j];
            k++;
            j++;
        }
    }
    if(j==b.size())
    {
       while(i<a.size())
        {
            v[k]=a[i];
            k++;
            i++;
        } 
    }
}
void merge_sort(vector<int>&v)
{
    int n=v.size();
    if (n <= 1)
    {
        return;
    }
    int n1=n/2;
    int n2=n-n1;
    vector<int>a(n1);
    vector<int>b(n2);
    for(int i=0;i<n1;i++)
    {
        a[i]=v[i];
    }
    for(int i=0;i<n2;i++)
    {
        b[i]=v[i+n1];
    }
    merge_sort(a);
    merge_sort(b);
    merging(a,b,v);
}
int main()
{
    int n;
    cout<<"enter size of array"<<endl;
    cin>>n;
    vector<int>v(n);
    for (int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    merge_sort(v);
    cout<<"your sorted array is "<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<v[i];
    }
    return 0;
}