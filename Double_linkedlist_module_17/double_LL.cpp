#include<iostream>
using namespace std;
class Node
{
    public:
    int val;
    Node * next;
    Node * prev;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
int main()
{
    Node * a1= new Node(10);
    Node * a2= new Node(20);
    Node * a3= new Node(30);
    a1->next=a2;
    a2->next=a3;
    
    a3->prev=a2;
    a2->prev=a1;

    Node * head=a1;
    while(head)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    return 0;
}