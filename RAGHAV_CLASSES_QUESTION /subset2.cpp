#include<iostream>
#include<vector>
#include<string>
using namespace std;
void printsubstr(string ans,string str,vector<string>&v,bool flag)
{
    if(str=="")
    {
        v.push_back(ans);
        return ;
    }
    char c=str[0];
    if(str.length()==1)
    {
        if (flag==true) printsubstr(ans+c,str.substr(1),v,true);
        printsubstr(ans,str.substr(1),v,true);
        return ;
    }
    char d=str[1];
    if(d==c)
    {
        if(flag==true) printsubstr(ans+c,str.substr(1),v,true);
        printsubstr(ans,str.substr(1),v,false);
    }
    else
    {
        if(flag==true) printsubstr(ans+c,str.substr(1),v,true);
        printsubstr(ans,str.substr(1),v,true);
    }
}
int main()
{
    string str="aab";
    vector<string>v;
    printsubstr("",str,v,true);
    for (int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}