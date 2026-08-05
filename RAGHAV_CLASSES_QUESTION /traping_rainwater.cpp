#include<iostream>
#include<vector>
using namespace std;
int main ()
{
    int h[]={0,1,0,2,1,0,1,3,2,1,2,1};
    int arr[12];
    int brr[12];
    //for previus greatest element is :
    int mp=h[0];
    arr[0]=-1;
    for (int i=1;i<12;i++)
    {
        arr[i]=mp;
        if (mp<h[i])
        {
            mp=h[i];
        }
    }
    //for next greatest element is :
    int mn=h[11];
    brr[11]=-1;
    for (int i=10;i>=0;i--)
    {
        brr[i]=mn;
    if (mn<h[i])
    {
        mn=h[i];
    }
    }
    //finding min btw next greatese and prev greatest
    int mini[12];
    for (int i=0;i<12;i++)
    {
        mini[i]=min(arr[i],brr[i]);
    }
    //finding water is 
    int w[12];
    for(int i=0;i<12;i++)
    {
        w[i]=max(0,mini[i]-h[i]);
    }
    //finding ans
    int s=0;
    for (int i=0;i<12;i++)
    {
        s=s+w[i];
    }
    cout<<s;
    return 0;
}