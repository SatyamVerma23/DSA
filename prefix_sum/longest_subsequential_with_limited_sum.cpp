#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int nums[]={4,5,2,1};
    int n=sizeof(nums)/sizeof(nums[0]);
    sort(nums, nums + n);
    int queries[]={3,10,21};
    int m=sizeof(queries)/sizeof(queries[0]);
    int v[m];
    for(int i=1;i<n;i++)
    {
        nums[i]+=nums[i-1];
    }
    for (int i=0;i<m;i++)
    {
        int len=0;
        for(int j=0;j<n;j++)
        {
            if(nums[j]>queries[i]) break;
            len++;
        }
        v[i]=len;
    }
    for(int i=0;i<m;i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}