#include<iostream>
using namespace std ;
class Node
{
    public:
    int val;
    Node*next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
Node* rotate_list(Node * head , Node* tail,int k,int n) //this is not int roate_list bcoz the function returns a node address, not an integer.
{
    Node* temp=head;
    if(head==NULL || head->next==NULL) 
    {
        return head;
    }
    if(k>n) k=k%n;
    if(k==0) return head;
    temp=head;
    for (int i=1;i<n-k;i++)
    {
        temp=temp->next;
    }
    tail->next=head;
    head=temp->next;
    temp->next=NULL;
    return head;
}
void display(Node * head)
{
    Node*temp=head;
    while (temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node* a1= new Node(1);
    Node* a2= new Node(2);
    Node* a3= new Node(3);
    Node* a4= new Node(4);
    Node* a5= new Node(5);
    a1->next=a2;
    a2->next=a3;
    a3->next=a4;
    a4->next=a5;
    a5->next=NULL;
    int k=2;
    int n=5;
    Node* newHead=rotate_list(a1,a5,k,n);//newHead ek pointer bna jo head ko point krega (just like node * newHead= head)
    display(newHead);
    return 0;
}