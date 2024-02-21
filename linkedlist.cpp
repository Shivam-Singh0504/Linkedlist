#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*next;
Node(int data)
{
   this->data=data;
   this->next=NULL;
}
~Node()
{
   int value=this->data;
   while(this->next!=NULL)
   {
      delete next;
      this->next=NULL;
   }
   cout<<"Memery deleted with value"<<value;
   cout<<endl;
}
};
void insertathead(Node* &head,int data)
{
Node*temp=new Node(data);
temp->next=head;
head=temp;
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
void insertattail(Node *&tail,int data)
{
   Node*temp=new Node(data);
   tail->next=temp;
   tail=temp;
}
void insertatposition(Node* & head,Node* &tail,int position,int data)
{
   if(position==1)
   {
      insertathead(head,data);
      return;
   }
   else{
      int count=1;
      Node *temp=head;
      while(count<position-1)
      {
         temp=temp->next;
         count++;
      }
      if(temp->next==NULL)
      {
         insertattail(tail,data);
         return;
      }
      Node *insertnode=new Node(data);
      insertnode->next=temp->next;
      temp->next=insertnode;

   }
}
void deletenode(Node* &head,Node* &tail,int position)
{
   if(position==1)
   {
   Node*temp=head;
   head=head->next;
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
         tail=prev;
         delete curr;
         return;
      }
      prev->next=curr->next;
      curr->next=NULL;
      delete curr;
   }
}
int main()
{
   Node* node1=new Node(12);
   Node*head=NULL;
   Node*tail=NULL;
   tail=node1;
   head=node1;
   insertathead(head,13);
   insertathead(head,15);
   insertathead(head,18);
   insertattail(tail,24);
   insertattail(tail,25);
   insertattail(tail,26);
   insertatposition(head,tail,2,30);
   insertatposition(head,tail,1,40);
   insertatposition(head,tail,10,50);
   print(head);
   cout<<head->data<<" ";
   cout<<tail->data<<endl;
   deletenode(head,tail,1);
   print(head);
   deletenode(head,tail,4);
   print(head);
   deletenode(head,tail,8);
   print(head);
   cout<<head->data<<" ";
   cout<<tail->data<<endl;
  
  


}