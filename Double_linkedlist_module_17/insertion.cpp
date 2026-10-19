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
class DLL
{
    public:
    Node * head;
    Node * tail;
    int size;
    DLL()
    {
        head=tail=NULL;
        size=0;
    }
    void insert_at_tail(int val)
    {
        Node * temp=new Node(val);
        if (size==0) head=tail=temp;
        else
        {
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
        }
        size++;
    }
    void insert_at_head(int val)
    {
        Node * temp=new Node(val);
        if (size==0) head=tail=temp;
        else
        {
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        size++;
    }
    void insert_at_idx(int idx,int val)
    {
        if(idx<0 || idx>size) 
        {
            cout<<"invalid";
        }
        else if(idx==0)
        {
            insert_at_head(val);
        }
        else if(idx==size)
        {
            insert_at_tail(val);
        }
        else 
        {
            Node* temp=head;
            Node * t= new Node(val);
            for (int i=1;i<idx-1;i++)
            {
                temp=temp->next;
            }
            t->next=temp->next;
            temp->next=t;
            t->prev=temp;
            t->next->prev=t;
            size++;
        }
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
};
int main()
{
    DLL list;
    list.insert_at_tail(10); //how to read --> list me jaa kr insert_at_tail finction chlao
    list.insert_at_tail(20);
    list.insert_at_tail(30);
    list.insert_at_tail(40);
    list.display();
    list.insert_at_head(50);
    list.display();
    list.insert_at_idx(3,100);
    list.display();
    return 0;
}