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
Node* merge_it(Node * a,Node* b)
{
    Node* c=new Node(100);///put random value
    Node *tc =c;
    while(a!=NULL && b!=NULL)
    {
        if(a->val <= b->val)
        {
            tc->next=a;
            tc=a;
            a=a->next;
        }
        else
        {
            tc->next=b;
            tc=b;
            b=b->next;
        }
    }
    if(a==NULL)
    {
        tc->next=b;//tc directly connect to remaing part of b
    }
    else
    {
        tc->next=a;//similar as above comment
    }
    return c->next;
}
Node* sorting1(Node* head)
{
    if(head==NULL || head->next==NULL) return head;//if size of LL is 0 or 1
    //to find left half of middle
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL) // this exp is done this  to find left half
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    //now slow is at end of first half
    Node* a=head;
    Node* b=slow->next;
    slow->next = NULL; //dissconet first half
    a=sorting1(a);
    b=sorting1(b);
    Node* c=merge_it(a,b);
    return c;
}
int main()
{
    Node* a1= new Node(5);
    Node* a2= new Node(1);
    Node* a3= new Node(3);
    Node* a4= new Node(6);
    Node* a5= new Node(2);
    Node* a6= new Node(4);
    a1->next=a2;
    a2->next=a3;
    a3->next=a4;
    a4->next=a5;
    a5->next=a6;
    a6->next= NULL;
    Node * head=sorting1(a1);
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    return 0;
}