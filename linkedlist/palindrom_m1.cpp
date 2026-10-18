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
    Node* c=new Node(0);//making new node with random value joo kiii copy of element contain krega
    //deep copy
    Node* temp=head;
    Node* tc=c;
    while(temp!=NULL)
    {
        Node* n=new Node(temp->val);//making dummy node 
        tc->next=n;
        temp=temp->next;
        tc=tc->next;
    }
    c=c->next;// considering element beyond random value
    c=reverse_of(c);
    Node* x=c;
    Node* y=head;
    while(x!=NULL || y!=NULL)
    {
        if(x->val==y->val)
        {
            x=x->next;
            y=y->next;
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
    Node* a4= new Node(2);
    Node* a5= new Node(1);
    a1->next=a2;
    a2->next=a3;
    a3->next=a4;
    a4->next=a5;

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