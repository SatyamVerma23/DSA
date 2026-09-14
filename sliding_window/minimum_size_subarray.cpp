#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int nums[]={1,2,4,6,3,4,3};
    int n=sizeof(nums)/sizeof(nums[0]);
    int t=10;
    int i=0,j=0;//i and j both point to 0 bcoz i denote first element of window always and j is used to add elements
    int s=0;
    int len; //calculate length
    int minlen=INT_MAX; ///store min length 
    while(j<n)
    {
        s+=nums[j];
        while(s>=t)
        {
            len=j-i+1;
            minlen=min(minlen,len);
            s=s-nums[i];// see your notes
            i++;
        }
        j++;
    }
    cout<<"your ans is "<<minlen;
    return 0;
}