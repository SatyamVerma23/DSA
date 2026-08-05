#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    int n;
    cout<<"enter no. of children"<<endl;
    cin>>n;
    int m;
    cout<<"enter no. of sizes array";
    cin>>m;
    vector<int>c(n);
    vector<int>s(m);
    cout<<"enter greed"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    cout<<"enter sizes"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    sort(c.begin(),c.end());
    sort(s.begin(),s.end());
    cout<<"displaying greed"<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<c[i];
    }
    cout<<endl;
    cout<<"displaying size"<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<c[i];
    }
    cout<<endl;
    int i=0;
    int j=0;
    int a=0;
    while(i<c.size() && j<s.size())
    {
        if(s[j]>=c[i])
        {
            a++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    cout<<"total distribute of cookies is"<<a;
    return 0;
}