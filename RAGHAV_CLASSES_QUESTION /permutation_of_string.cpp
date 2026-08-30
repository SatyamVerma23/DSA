#include<iostream>
#include<string>
using namespace std;
void permutation(string ans,string str)
{
    if(str=="")
    {
        cout<<ans<<endl;
        return;
    }
    // loop ka use kiya ja rha taki jitna character h utne barr recursion call kiya ja ske
    for(int i=0;i<str.length();i++)
    {
        char c=str[i];
        // neeche wala code isliye taki ek particular element ko choor kr (i.e str[i]) baki sb liya ja ske
        string left=str.substr(0,i); //include elemnt of i , but exclude i
        string right=str.substr(i+1); //for lement of i+1 to last element
        permutation(ans+c,left+right);
    }
}
int main()
{
    string str="abc";
    permutation("",str);
}