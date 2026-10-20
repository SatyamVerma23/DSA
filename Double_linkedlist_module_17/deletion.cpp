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
    void dlt_at_head()
    {
        if(size==0)
        {
            cout<<"emty list";
            return ;
        }
        head=head->next;
        if(head!=NULL) head->prev=NULL;
        if(head==NULL) tail=NULL;
        size--;
    }
    void dlt_at_tail()
    {
        if(size==0)
        {
            cout<<"emty list";
            return ;
        }
        Node * temp=tail->prev;
        temp->next=NULL;
        tail=temp;
        size--;
    }
    void dlt_at_idx(int idx)
    {
        if (size==0)
        {
            cout<<"empty list";
        }
        else if(idx<0 || idx>=size)
        {
            cout<<"invalid";
            return ;
        }
        else if(idx==1)
        {
            dlt_at_head();
        }
        else if(idx==size-1)
        {
            dlt_at_tail();
        }
        else
        {
            Node * temp=head;
            for (int i=1;i<idx-1;i++)
            {
                temp=temp->next;
            }
            temp->next=temp->next->next;
            temp->next->prev=temp;
            size--;
        }
    }
};
int main()
{
    DLL list;
    list.insert_at_tail(10); //how to read --> list me jaa kr insert_at_tail finction chlao
    list.insert_at_tail(20);
    list.insert_at_tail(30);
    list.insert_at_tail(40);
    list.insert_at_tail(50);
    list.insert_at_tail(60);
    list.insert_at_tail(70);
    list.insert_at_tail(80);
    list.display();
    list.dlt_at_head();
    list.display();
    list.dlt_at_tail();
    list.display();
    list.dlt_at_idx(2);
    list.display();
    return 0;
}