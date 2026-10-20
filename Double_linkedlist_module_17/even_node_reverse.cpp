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
Node* reverse_of(Node* head)
{
    if(head==NULL || head->next==NULL) return head;
    Node * newhead=reverse_of(head->next);
    head->next->next=head;//
    head->next=NULL;
    return newhead;
}
Node * reverse_partial(Node * head,int left,int right)
{
    Node * temp=head;
    int n=1;
    Node* a=NULL;
    Node* b=NULL;
    Node* c=NULL;
    Node* d=NULL;
    while(temp!=NULL)
    {
        if(n==left-1) a=temp;
        if(n==left) b=temp;
        if(n==right) c=temp;
        if(n==right+1) d=temp;
        temp=temp->next;
        n++;
    }
    // below code explaination see in copy
    if(a!=NULL) a->next=NULL; 
    c->next=NULL;//cut connection of c with d
    c=reverse_of(b); //making reverse totally with node name and value
    if(a) a->next=c;
    b->next=d;
    if(a) return head;
    return c; // if a not even initalise then c is your first node
}
Node * even_reverse(Node * head)
{
    Node * temp=head;
    int gap=1;
    while(temp && temp->next)
    {
        int remaining_len=0;// (see in notes)to check or make correction for last group of node
        Node * t=temp->next;
        for (int i=1;i<=gap+1 && t!=NULL;i++)
        {
            t=t->next;
            remaining_len++;
        }
        if(remaining_len<gap+1)// making actual gap value
        {
            gap=remaining_len-1;
        }
        if (gap%2!=0)
        {
            reverse_partial(temp,2,2+gap);
        }
        gap++;
        for (int i=1;temp!=NULL && i<=gap;i++)
        {
            temp=temp->next;
        }
    }
    return head;
}
int main()
{
    Node * a1=new Node(5);
    Node * a2=new Node(2);
    Node * a3=new Node(6);
    Node * a4=new Node(3);
    Node * a5=new Node(9);
    Node * a6=new Node(1);
    Node * a7=new Node(7);
    Node * a8=new Node(3);
    Node * a9=new Node(8);
    Node * a10=new Node(4);
    a1->next=a2;
    a2->next=a3;
    a3->next=a4;
    a4->next=a5;
    a5->next=a6;
    a6->next=a7;
    a7->next=a8;
    a8->next=a9;
    a9->next=a10;

    Node * head=even_reverse(a1);
    while(head)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
}