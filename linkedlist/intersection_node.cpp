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
int intersection(Node * heada,Node* headb)
{
    Node *tempA=heada;
    Node *tempB=headb;
    int lA=0;
    while(tempA!=NULL)
    {
        lA++;
        tempA=tempA->next;
    }
    int lB=0;
    while(tempB!=NULL)
    {
        lB++;
        tempB=tempB->next;
    }
    tempA=heada;// temp ko waps head a pr la diye taki do ko starting se equal laya ja ske
    tempB=headb;
    if(lA>lB)
    {
        int diff=lA-lB;
        for (int i=1;i<=diff;i++)
        {
            tempA=tempA->next;
        }
        while(tempA!=tempB) //for finding intersection node
        {
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempA->val; // tempa ya tempb do mein se kisi ka v value return kr skti ho kyu dono h same node ko poinrt kr rhe hai.
    }
    else
    {
        int diff=lB-lA;
        for (int i=1;i<=diff;i++)
        {
            tempB=tempB->next;
        }
        while(tempA!=tempB) //for finding intersection node
        {
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempB->val;
    }
}
int main()
{
    Node* a1= new Node(10);
    Node* a2= new Node(1);
    Node* a3= new Node(2);
    Node* a4= new Node(3);
    Node* a5= new Node(4);
    Node* a6= new Node(5);
    Node* a7= new Node(6);
    Node* a8= new Node(7);
    Node* b1= new Node(1);
    Node* b2= new Node(3);
    Node* b3= new Node(4);
    a1->next=a2;
    a2->next=a3;
    a3->next=a4;
    a4->next=a5;
    a5->next=a6;
    a6->next=a7;
    a7->next=a8;
    a8->next=NULL;
    b1->next=b2;
    b2->next=b3;
    b3->next=a6;
    cout<<"intersection point is "<<intersection(a1,b1);
    return 0;
}