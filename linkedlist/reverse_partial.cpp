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
int main()
{
    Node* a1= new Node(10);
    Node* a2= new Node(20);
    Node* a3= new Node(30);
    Node* a4= new Node(40);
    Node* a5= new Node(50);
    Node* a6= new Node(60);
    Node* a7= new Node(70);
    Node* a8= new Node(80);
    
    a1->next=a2;
    a2->next=a3;
    a3->next=a4;
    a4->next=a5;
    a5->next=a6;
    a6->next=a7;
    a7->next=a8;

    Node * head=reverse_partial(a1,3,5);
    Node* temp=head;
    while(temp)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    return 0;
}