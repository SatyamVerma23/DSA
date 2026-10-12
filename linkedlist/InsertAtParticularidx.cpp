#include<iostream>
using namespace std;
class Node
{
    public:
    int val;
    Node* next;
    Node(int val)
    {
        this ->val=val;
        this->next=NULL;
    }
};
class linkedlist 
{
    public:
    Node* head;
    Node* tail;
    int size;
    linkedlist()//for giving intial value to every parameter (like size =0)
    {
        head=tail=NULL;
        size=0;
    }
    void insertAtEnd(int val)
    {
        Node*temp =new Node(val);
        if(size==0)
        {
            head=tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
    void display()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void insertAtBeginning(int val)
    {
        Node * temp=new Node(val);
        temp->next=head;
        head=temp;
        size++;
    }
    void insertAtParticularidx(int idx,int val)
    {
        if(idx<0 || idx>size)
        {
            cout<<"invalid"<<endl;
        }
        else if(idx==0) insertAtBeginning(val);
        else if(idx==size) insertAtEnd(val);
        else
        {
            Node* t=new Node(val);
            Node *temp =head;
            for (int i=1;i<idx-1;i++)
            {
                temp=temp->next;
            }
            t->next=temp->next;
            temp->next=t;
            size++;
        }
    }
};
int main()
{
    linkedlist ll;
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);
    ll.insertAtEnd(50);
    ll.insertAtEnd(60);
    ll.display();
    ll.insertAtParticularidx(3,90);
    ll.display();
    return 0;
}