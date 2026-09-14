#include<iostream>
using namespace std;
int main()
{
    int arr[]={2,-3,4,4,-7,-1,4,-2,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=4;
    int ans[n-k+1];// bcoz total 6 windows are form
    int previdx=-1;// to store idx of negative value
    for(int i=0;i<k;i++)
    {
        if(arr[i]<0)
        {
            previdx=i;
            ans[0]=arr[previdx];
            break;
        }
    }
    int i=1;// bcoz we alredy find ans of first window
    int j=k;
    while(j<n)
    {
        if(previdx>=i)
        {
            ans[i]=arr[previdx];
        }
        else
        {
            for (previdx=i;previdx<=j;previdx++)
            {
                if(arr[previdx]<0)
                {
                    ans[i]=arr[previdx];
                    break;
                }
                
            }
        }
        i++;
        j++;
    }
    for (int i=0;i<n-k+1;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}