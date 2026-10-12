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
};
int main()
{
    linkedlist ll; //just like vector<int> ll
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.display();
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);
    ll.display();
    cout<<ll.size; // (we denote in this form bcoz size is data form)to find length of linked list 
    return 0;
}