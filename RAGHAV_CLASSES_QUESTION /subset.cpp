#include<iostream>
#include<string>
using namespace std;
void subset(string ans,string str)
{
    if(str=="")
    {
        cout<<ans<<endl;
        return;
    }
    char c=str[0];
    subset(ans+c,str.substr(1));
    subset(ans,str.substr(1));
}
int main()
{
    string str="abc";
    subset("",str);
    return 0;
}