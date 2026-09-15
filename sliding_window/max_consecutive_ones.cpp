#include<iostream>
using namespace std;
int main()
{
    int arr[]={1,0,1,1,0,0,1,1,1,1,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    int i=0,j=0;
    int l=0,maxlen=INT_MIN;
    int flip=0;
    while(j<n)
    {
        if(arr[j]==1) 
        {
            j++;
        }
        else//(nums[j]==0)
        {
            if(flip<k)
            {
                flip++;
                j++;//without make actual element  0 to 1(only consider in mind that we make jth elemnt to be 1)
            }
            else// flip==k
            {
                l=j-i; //cal lenght 
                maxlen=max(maxlen,l);
                while (arr[i]==1) i++; /// to shift i just befor first zero of that window

                i++;
                j++;
            }
        }
    }
    l=j-i;
    maxlen=max(maxlen,l);
    cout<<maxlen;
    return 0;
}