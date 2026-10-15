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
int main()
{
    Node* a1= new Node(1);
    Node* a2= new Node(2);
    Node* a3= new Node(5);
    a1->next=a2;
    a2->next=a3;
    a3->next= NULL;

    Node* b1= new Node(2);
    Node* b2= new Node(3);
    Node* b3= new Node(4);
    Node* b4= new Node(6);
    Node* b5= new Node(7);
    Node* b6= new Node(8);
    b1->next=b2;
    b2->next=b3;
    b3->next=b4;
    b4->next=b5;
    b5->next=b6;
    b6->next=NULL;

    Node * head=merge_it(a1,b1);
    while(head!=NULL)
    {
        cout<<head->val;
        head=head->next;
    }
    return 0;
}