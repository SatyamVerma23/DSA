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
Node* reverse_of(Node* head)
{
    if(head==NULL || head->next==NULL) return head;
    Node * newhead=reverse_of(head->next);
    head->next->next=head;//
    head->next=NULL;
    return newhead;
}
Node* reorder(Node * head)
{
    Node* s=head;
    Node* f=head;
    while(f!=NULL && f->next!=NULL)
    {
        s=s->next;
        f=f->next->next;
    }
    Node* temp=head;
    while(temp->next!=s)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    Node* bs = s;
    s = reverse_of(bs);
    Node * a=head;//making list of first 
    Node * ta=a;
    Node * b=s;
    Node * tb=b;

    Node * c=new Node (0);
    Node* tc=c;

    while(ta != NULL && tb != NULL)
    {
        tc->next=ta;
        ta=ta->next;
        tc = tc->next; 

        tc->next=tb;
        tb=tb->next;
        tc = tc->next; 
    }
    // attach remaining nodes 
    if(ta != NULL) tc->next = ta;
    if(tb != NULL) tc->next = tb;
    return c->next;
}
int main()
{
    Node* a1= new Node(1);
    Node* a2= new Node(2);
    Node* a3= new Node(3);
    Node* a4= new Node(4);
    Node* a5= new Node(5);
    Node* a6= new Node(6);
    a1->next=a2;
    a2->next=a3;
    a3->next=a4;
    a4->next=a5;
    a5->next=a6;
    a6->next=NULL;
    Node * head=reorder(a1);
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    return 0;
}