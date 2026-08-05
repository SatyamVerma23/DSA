#include<iostream>
#include<climits>
using namespace std;
int main()
{
            // 0,1,2,3,4,5,6,7,8
    int arr[]={9,6,4,2,3,5,7,0,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0;
    while(i<n)
    {
        if(arr[i]>=n) i++; //if element is greater than size of array like 9 is beyod that array size
        else if(arr[i]==i) i++; //if element is at right index then move forward
        else //if element is not at right index then make them at right index
        {
            int ci=arr[i];
            swap(arr[i],arr[ci]);
        }
    }
    for (int i=0;i<n;i++) // checking the missing number by matching arr[i] with i
    {
        if(arr[i]!=i)
        {
            cout<<"missing no. is "<<i;
            break;
        }
    }
    return 0;
}
