#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    int n;
    cout<<"enetr size of array"<<endl;
    cin>>n;
    int visited[n];
    for (int i=0;i<n;i++)
    {
        visited[i]=0;
    }
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
    int x=0;
    for(int i=0;i<n;i++)
    {
        int min=INT_MAX;
        int idx=-1;
        for(int j=0;j<n;j++)
        {
            if(visited[j]==1) continue;
            else
            {
                if(min>v[j])
                {
                    min=v[j];
                    idx=j;
                }
            }
        }
        v[idx]=x;
        x++;
        visited[idx]=1;
    }
    for (int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;

}