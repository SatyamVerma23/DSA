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
int main()
{
    Node* a= new Node(10);
    Node* b= new Node(20);
    Node* c= new Node(30);
    Node* d= new Node(40);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=NULL;// this is by default
    //for triverse printing
    Node* temp=a;//temp box k andr a ka add value store h
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        //to shift temp box at next node
        temp=temp->next;
    }
}