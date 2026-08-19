#include<iostream>
using namespace std;
int find(int sr,int sc,int er,int ec)
{
    if(sr>er || sc>ec) return 0;
    if(sr==er && sc==ec) return 1;
    int rightway=find(sr,sc+1,er,ec);
    int downway=find(sr+1,sc,er,ec);
    return rightway+downway;
}
int main()
{
    int m=3;
    int n=3;
    cout<<"your total no. of possibility is "<<find(0,0,m-1,n-1);
    return 0;
}