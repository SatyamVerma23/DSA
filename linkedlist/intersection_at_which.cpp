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
Node*  detect_cycle(Node * head)
{
    Node* s=head;//slow
    Node* f=head;//fast 
    Node* t=head;//temp (t ko tb tk nhi chlana h jb tk s==f n ho jaye)
    bool flag=false; //check weather any loop or not 
    while(f!=NULL && f->next!=NULL) //to make s==f
    {
        s=s->next;
        f=f->next->next;
        if(s==f)
        {
            flag = true;
            break;
        }
    }
    if(flag==false) return NULL;
    else
    {
        while (t!=s) //ab t or s ko chla kr t==s krenge whi pr intersection node miljayega
        {
            s=s->next;
            t=t->next;
        }
        return s;
    }
    return s;
}
int main()
{
    Node* a1= new Node(1);
    Node* a2= new Node(2);
    Node* a3= new Node(3);
    Node* a4= new Node(3);
    Node* a5= new Node(5);
    a1->next=a2;
    a2->next=a3;
    a3->next=a4;
    a4->next=a5;
    a5->next=a3;
    cout<<"intersection point is at "<<detect_cycle(a1)->val;
    return 0;
}