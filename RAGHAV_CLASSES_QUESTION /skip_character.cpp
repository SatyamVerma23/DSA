#include<iostream>
using namespace std;
void skip(string s,string str,int idx)
{
    if(idx == str.length())
    {
        cout<<s;
        return ;
    }
    char ch=str[idx];
    if(str[idx]=='a') skip(s,str,idx+1);
    else skip(s+ch,str,idx+1);
}
int main()
{
    string str="ababdhar";
    skip("",str,0);
    return 0;
}