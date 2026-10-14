#include<iostream>
using namespace std;
class Node{  //(this user define data type) mean create node linke create array,vector
    public:
    int val;
    Node* next;
    //making constructur
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};
class linkedlist{  //(this user define data structure) means Manages the entire linked list
    public:
    Node* head;
    Node* tail;
    int size;
    linkedlist(){
        head=tail=NULL;
        size =0;
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
        if (size == 0)
        {
            tail = temp;
        }
        size++;
    }
    int getElement(int idx)
    {
        if(idx<0 || idx>=size)
        {
            cout<<"invalid idx"<<endl;
            return -1;
        }
        else if(idx==0) return head->val;
        else if(idx==size-1) return tail->val;
        else
        {
            Node*temp=head;
            for (int i=1;i<=idx;i++)
            {
                temp=temp->next;
            }
            return temp->val;
        }
    }
    void dltAthead()
    {
        if(size==0)
        {
            cout<<"empty"<<endl;
        }
        else if(size==1)
        {
            head=tail=NULL;
            size--;
        }
        else
        {
            head=head->next;
            size--;
        }
    }
    void dltAtend()
    {
        Node* temp=head;
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
        temp->next=NULL;
        tail=temp;
    }
    void dltAtParticularidx(int idx)
    {
        if(idx<0 || idx>=size) 
        {
            cout<<"invalid"<<endl;
        }
        else if(idx==0) 
        {
            dltAthead();
        }
        else if(idx==size-1)
        {
            dltAtend();
        }
        else
        {
            Node*temp=head;
            for (int i=1;i<=idx-1;i++)
            {
                temp=temp->next;
            }
            temp->next=temp->next->next;
            size--;
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
    ll.insertAtEnd(70);
    ll.insertAtEnd(80);
    ll.display();
    cout<<ll.size<<endl; 
    //for getelements
    cout<<"displaying particular index is ";
    cout<<ll.getElement(3)<<endl; //starting idx from 0 thatswhy is display 40 at idx 3
    //for dlt element 
    ll.dltAthead();
    ll.display();
    ll.dltAtend();
    ll.display();
    ll.dltAtParticularidx(3);
    ll.display();
    return 0;
}