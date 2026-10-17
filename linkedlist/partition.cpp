#include<iostream>
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
Node* partition_of(Node * head,int target)
{
    Node* t=head;
    Node* lo=new Node(0);// new node with random value
    Node* tl=lo;// temp of lo
    Node* hi=new Node(0);// new node with random value
    Node* th=hi;
    while(t!=NULL)
    {
        if(t->val>= target)
        {
            th->next=t;
            th=t;
        }
        else 
        {
            tl->next=t;
            tl=t;
        }
        t=t->next;
    }
    tl->next=hi->next;// connecting last node lower than target with first node which is greater than target 
    th->next=NULL;// make last node (which is greater than target) is NULL
    return head;
}
int main()
{
    Node* a1= new Node(10);
    Node* a2= new Node(80);
    Node* a3= new Node(40);
    Node* a4= new Node(30);
    Node* a5= new Node(60);
    Node* a6= new Node(70);
    Node* a7= new Node(15);
    a1->next=a2;
    a2->next=a3;
    a3->next=a4;
    a4->next=a5;
    a5->next=a6;
    a6->next=a7;
    a7->next=NULL;
    Node * head=partition_of(a1,41);
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    return 0;
}