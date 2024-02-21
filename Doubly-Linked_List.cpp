#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*next;
Node* prev;
Node(int data)
{
   this->data=data;
   this->next=NULL;
   this->prev=NULL;
}
~Node()
{
   int value=this->data;
   while(next!=NULL)
   {
      delete next;
      next=NULL;
   }
   cout<<"Memery deleted with value"<<value;
   cout<<endl;
}
};
void insertathead(Node* &head,int data)
{
    Node*temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;

}
void insertattail(Node* &tail,int data)
{
    Node* temp=new Node( data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void insertatposition(Node* &head, Node* &tail,int position,int data)
{
    if(position==1)
    {
        insertathead(head,data);
        return;
    }
    else{
        int count=1;
        Node*temp=head;
        while(count<position-1)
        {
            temp=temp->next;
            count++;
        }
        if(temp->next==NULL)
        {
            insertattail(tail,data);
        }
            Node * insertnode=new Node(data);
            insertnode->next=temp->next;
            temp->next->prev=insertnode;
            insertnode->prev=temp;
            temp->next=insertnode;

    }
}
void print(Node* &head)
{
   Node *temp=head;
   while(temp!=NULL)
   {
      cout<<temp->data<<" ";
      temp=temp->next;
   }
   cout<<endl;
}
void deletenode(Node *&head,Node* &tail,int position)
{
    if(position==1)
    {
        Node*temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;
    }
    else{
        int count=1;
        Node *prev=NULL;
        Node *curr=head;
        while(count<position)
        {
            prev=curr;
            curr=curr->next;
            count++;
        }
        if(curr->next==NULL)
        {
            prev->next=NULL;
            curr->prev=NULL;
            tail=prev;
            delete curr;
            return;
        }
        prev->next=curr->next;
        curr->next->prev=curr->prev;
        curr->next=NULL;
        curr->prev;
        delete curr;

    }
}
int main()
{
    Node* node1=new Node(10);
    Node *head=node1;
    Node *tail=node1;
    insertathead(head,20);
    insertattail(tail,30);
    insertatposition(head,tail,1,50);
    insertatposition(head,tail,4,50);
    insertatposition(head,tail,3,50);
    print(head);
    cout<<head->data<<" ";
    cout<<tail->data<<endl;
    deletenode(head,tail,1);
    print(head);
    cout<<head->data<<" ";
    cout<<tail->data;
    deletenode(head,tail,2);
    print(head);
    cout<<head->data<<" ";
    cout<<tail->data<<endl;
    deletenode(head,tail,4);
    print(head);
    cout<<head->data<<" ";
    cout<<tail->data<<endl;

}