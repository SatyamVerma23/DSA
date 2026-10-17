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
    Node* head=reverse_of(a1);
    
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    return 0;
}