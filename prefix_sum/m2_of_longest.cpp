#include<iostream>
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
        int lo=0;
        int hi=n-1;
        int mid;
        while (lo<=hi)
        {
            mid=lo+(hi-lo)/2;
            if(nums[mid]>queries[i])
            {
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        v[i]=lo;
    }
    for (int i=0;i<m;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}