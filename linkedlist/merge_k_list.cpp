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
Node* merge_it(Node * a,Node* b)
{
    Node* c=new Node(100);///put random value
    Node *tc =c;
    while(a!=NULL && b!=NULL)
    {
        if(a->val <= b->val)
        {
            tc->next=a;
            tc=a;
            a=a->next;
        }
        else
        {
            tc->next=b;
            tc=b;
            b=b->next;
        }
    }
    if(a==NULL)
    {
        tc->next=b;//tc directly connect to remaing part of b
    }
    else
    {
        tc->next=a;//similar as above comment
    }
    return c->next;
}
Node* merge_k_ll(vector<Node*>&arr)
{
    if(arr.size()==0) return NULL;
    while(arr.size()>1)
    {
        Node* a=arr[0];
        arr.erase(arr.begin());
        Node* b=arr[0];
        arr.erase(arr.begin());
        Node* c=merge_it(a,b); // first  or second elemnt ko le kr merge kr diya 
        arr.push_back(c); /// merge krne k baad last mein push kr diya .
    }
    return arr[0]; // pura operaion hone k baad 1 h element bchega usi ko return kr diya.
}
int main()
{
    //taking example with 3 ll a,b,c


    Node* a1= new Node(1);
    Node* a2= new Node(2);
    Node* a3= new Node(5);
    a1->next=a2;
    a2->next=a3;
    a3->next= NULL;

    Node* b1= new Node(2);
    Node* b2= new Node(3);
    Node* b3= new Node(4);
    Node* b4= new Node(6);
    Node* b5= new Node(7);
    Node* b6= new Node(8);
    b1->next=b2;
    b2->next=b3;
    b3->next=b4;
    b4->next=b5;
    b5->next=b6;
    b6->next=NULL;

    Node* c1= new Node(12);
    Node* c2= new Node(13);
    Node* c3= new Node(14);
    Node* c4= new Node(16);
    Node* c5= new Node(17);
    Node* c6= new Node(18);
    c1->next=c2;
    c2->next=c3;
    c3->next=c4;
    c4->next=c5;
    c5->next=c6;
    c6->next=NULL;

    vector<Node*>arr;
    arr.push_back(a1);
    arr.push_back(b1);
    arr.push_back(c1);

    Node * head=merge_k_ll(arr);
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    return 0;
}