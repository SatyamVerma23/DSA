#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string c="YYNY";
    int n=c.length();
    int suffixY[n+1];
    int prefixN[n+1];
    int ans[n+1];
    for (int i=0;i<=n;i++)
    {
        int idx=0;
        int countn=0;
        while (idx<i)
        {
            if(c[idx]=='N')
            {
                countn++;
            }
            idx++;
        }
        prefixN[i]=countn;
    }
    for(int i=0;i<=n;i++)
    {
        int idx=i;
        int county=0;
        while(idx<n)
        {
            if(c[idx]=='Y')
            {
                county++;
            }
            idx++;
        }
        suffixY[i]=county;
    }
    for (int i=0;i<=n;i++)
    {
        ans[i]=prefixN[i]+suffixY[i];
    }
    int minpenlity=INT_MAX;
    int idx=-1;
    for (int i=0;i<=n;i++)
    {
        if(minpenlity>ans[i])
        {
            minpenlity=ans[i];
            idx=i;
        }
    }
    cout<<"minimum penality is "<<minpenlity<<" at index "<<idx;
}