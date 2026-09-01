#include<iostream>
#include<string>
using namespace std;
string cas(int n)
{
    if(n==1) return "1";
    string str=cas(n-1);
    int f=1;
    string ans="";
    char ch=str[0];
    for (int i=0;i<str.length();i++)
    {
        char dh=str[i];
        if(ch==dh)
        {
            f++;
        }
        else
        {
            ans += (to_string(f)+ch);
            f=1;
            ch=dh;
        }
    }
    ans += (to_string(f)+ch); // this line is used to denote last number of string
    return ans;
}
int main()
{
    int n=7;
    cout<<cas(n);
    return 0;
}