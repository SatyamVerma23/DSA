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
bool palindrom(Node* head)
{
   Node * s=head;
   Node * f=head;
   while(f!=NULL && f->next!=NULL)
   {
    s=s->next;
    f=f->next->next;
   }
   Node* newhead=reverse_of(s);
   Node * a=head;
   Node * b=newhead;
   while(b!=NULL)
   {
    if(a->val==b->val)
    {
        a=a->next;
        b=b->next;
    }
    else
    {
        return false;
    }
   }
   return true;
}
int main()
{
    Node* a1= new Node(1);
    Node* a2= new Node(2);
    Node* a3= new Node(3);
    Node* a4= new Node(3);
    Node* a5= new Node(2);
    Node* a6= new Node(1);
    
    a1->next=a2;
    a2->next=a3;
    a3->next=a4;
    a4->next=a5;
    a5->next=a6;

    bool f=palindrom(a1);

    if(f==true)
    {
        cout<<"yes";
    }
    else
    {
        cout<<"no";
    }
    return 0;
}