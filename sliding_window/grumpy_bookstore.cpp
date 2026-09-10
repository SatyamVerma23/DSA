#include<iostream>
using namespace std;
int main()
{
    int customer[]={1,0,1,2,1,1,7,5};
    int n=sizeof(customer)/sizeof(customer[0]);
    int grumpy[]={0,1,0,1,0,1,0,1};
    int prevloss=0;
    int maxloss=0;
    int idx=-1;
    int min=3;
    for (int i=0;i<min;i++)
    {
        if(grumpy[i]==1) prevloss+=customer[i];
    }
    maxloss=prevloss;
    int i=1;
    int j=min;
    int currentloss=0;
    while(j<n)
    {
        int currentloss=prevloss;
        if(grumpy[j]==1) currentloss+=customer[j];
        if(grumpy[i]==1) currentloss-=customer[i-1];
        if(maxloss<currentloss)
    {
        maxloss=currentloss;
        idx=i;
    }
    prevloss=currentloss;
    i++;
    j++;
    }
    for (int i=idx;i<idx+min;i++)
    {
        grumpy[i]=0;
    }
    int s=0;
    for (int i=0;i<n;i++)
    {
        if(grumpy[i]==0) s+=customer[i];
    }
    cout<<"total satisfied customer is "<<s;
}

