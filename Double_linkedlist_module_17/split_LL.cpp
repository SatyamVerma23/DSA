#include<iostream>
#include<vector> 
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};
vector<Node*>split(Node * head,int k)
{
    int n=0;
    Node* temp=head;
    while(temp)
    {
        temp=temp->next;
        n++;
    }
    vector<Node*>ans;
    int size=n/k;
    int r=n%k;
    temp=head;
    while(temp)
    {
        Node * c= new Node(0);
        Node * tc=c;
        int s=size;//to make sure not lost of original size
        if(r>0)
        {
            s++;
            r--;
        }
        for (int i=1;i<=s;i++)
        {
            tc->next=temp;
            temp=temp->next;
            tc=tc->next;
        }
        tc->next=NULL;
        ans.push_back(c->next);
    }
    if (ans.size()<k)
    {
        int extra=k-ans.size();
        for(int i=1;i<=extra;i++)
        {
            ans.push_back(NULL);
        }
    }
    return ans;
}
int main()
{
    Node* a1= new Node(1);
    Node* a2= new Node(2);
    Node* a3= new Node(3);
    Node* a4= new Node(4);
    Node* a5= new Node(5);
    Node* a6= new Node(6);
    Node* a7= new Node(7);
    Node* a8= new Node(8);
    Node* a9= new Node(9);
    Node* a10= new Node(10);
    Node* a11= new Node(11);
    a1->next=a2;
    a2->next=a3;
    a3->next=a4;
    a4->next=a5;
    a5->next=a6;
    a6->next=a7;
    a7->next=a8;
    a8->next=a9;
    a9->next=a10;
    a10->next=a11;
   
    vector<Node*> ans=split(a1,3);
    for(int i=0;i<ans.size();i++)
    {
        Node* temp=ans[i]; 
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}