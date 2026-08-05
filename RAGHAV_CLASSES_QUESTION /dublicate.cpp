#include<iostream>
using namespace std;
int main()
{
    int arr[]={3,1,3,4,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0;
    while(i<n)
    {
        if(arr[i]==i+1) i++;//if element iat right index then move forward
        else // if element is not at right index
        {
            int ci=arr[i]-1;
            if(arr[ci]==arr[i]) //befor swaping check that Is there any coorect element placed at correct index? 
            {
                cout<<"dublicate no. is "<<arr[i];
                break;
            }
            swap(arr[i],arr[ci]);
        }
    }
    return 0;
}