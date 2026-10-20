#include<iostream>
#include<vector>
using namespace std;
class Node
{
    public:
    int val;
    Node* next;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};
vector<int>min_max(Node * head)
{
    vector<int>ans;
    int idx=1;//to intialize idx value with 1 not 0
    int fidx=-1;
    int sidx=-1;
    int max_dist=INT_MIN;
    int dist=0;
    Node * a=head;
    Node * b=head->next;
    Node * c=head->next->next;
    while(c)
    {
        if(b->val>a->val && b->val>c->val || b->val<a->val && b->val<c->val)
        {
            if(fidx==-1) fidx=idx;
            else sidx=idx;
        }
        a=a->next;
        b=b->next;
        c=c->next;
        idx++;
    }
    // itna krne se actual cp of max dist mil jayega
    if (sidx==-1) 
    {
        ans.push_back(-1);
    }
    max_dist=sidx-fidx;
    ans.push_back(max_dist);
    ///till now we find max node btw critical nodes
    //.....mow we find min node
    int min_dist=INT_MAX;
    fidx=-1;
    sidx=-1;
    idx=1;
    a=head;
    b=head->next;
    c=head->next->next;
    while(c)
    {
        if(b->val>a->val && b->val>c->val || b->val<a->val && b->val<c->val)
        {
            fidx=sidx;
            sidx=idx;
            if(fidx!=-1)
            {
                int d=sidx-fidx;
                min_dist=min(min_dist,d);
            }
        }
        a=a->next;
        b=b->next;
        c=c->next;
        idx++;
    }
    ans.push_back(min_dist);
    return ans;
}
int main()
{
    Node * a1=new Node(5);
    Node * a2=new Node(3);
    Node * a3=new Node(1);
    Node * a4=new Node(2);
    Node * a5=new Node(5);
    Node * a6=new Node(1);
    Node * a7=new Node(2);
    a1->next=a2;
    a2->next=a3;
    a3->next=a4;
    a4->next=a5;
    a5->next=a6;
    a6->next=a7;
    vector<int>ans=min_max(a1);
    cout<<"ans is ";
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}