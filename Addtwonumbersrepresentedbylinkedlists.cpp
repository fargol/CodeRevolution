#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;
};
struct Node *newNode(int data)
{
    struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}
 struct Node* addTwoLists (struct Node* first, struct Node* second);
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_Node = newNode(new_data);
    new_Node->next = (*head_ref);
    (*head_ref)    = new_Node;
}
void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
void freeList(struct Node *Node)
{
	struct Node* temp;
    while(Node != NULL)
    {   
        temp=Node;
        Node = Node->next;
        free(temp);
    } 
}
Node* reverse(Node *first,Node *&head){
  if(first->next==NULL){
    head=first;
    return first;
  }
  else{
    Node *temp=reverse(first->next,head);
    temp->next=first;
    first->next=NULL;
    return first;
  }
}
int main(void)
{
   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {
	   struct Node* res = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;
	    cin>>n;
	    for(i=0;i<n;i++)
	    {
			cin>>x;
			push(&first, x);
	    }
         cin>>m;
	    for(i=0;i<m;i++)
	    {
			cin>>x;
	    push(&second, x);
	    }
      Node *head;
      reverse(first,head);
      first=head;
      reverse(second,head);
      second=head;
		 res = addTwoLists(first, second);
	    printList(res);
if(first)
freeList(first);
if(second)
freeList(second);
//if(res)
//freeList(res);
   }
   return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*struct Node
{
    int data;
   Node* next;
}; */
//write a function returns the resultant linked list
void add(Node *first,Node *second,Node *&head,int &carry){
  head=new Node;
  if(first->next==NULL&&second->next==NULL){
    head->data=first->data+second->data;
    carry=head->data/10;
    head->data%=10;
    head->next=NULL;
  }
  else{
    add(first->next,second->next,head->next,carry);
    head->data=first->data+second->data+carry;
    carry=head->data/10;
    head->data%=10;
  }
}
void getLength(Node *head,int &l){
  if(head==NULL)
    return;
  else{
    l++;
    getLength(head->next,l);
  }
}
void addDiff(Node *first,Node *second,int diff,Node *&head,int &carry){
    if(diff==0)
      add(first,second,head,carry);
    else{
      addDiff(first->next,second,diff-1,head,carry);
      Node *temp=new Node;
      temp->data=first->data+carry;
      carry=temp->data/10;
      temp->data%=10;
      temp->next=head;
      head=temp;
    }
}
Node* addTwoLists(Node* first, Node* second){
  // Code here
  int l1=0,l2=0;
  getLength(first,l1);
  getLength(second,l2);
  Node *head;
  int carry=0;
   if(l1==l2){
      add(first,second,head,carry);
    }
    else{
      int diff;
      if(l1>l2){
        diff=l1-l2;
        addDiff(first,second,diff,head,carry);
      }
      else{
        diff=l2-l1;
        addDiff(second,first,diff,head,carry);
      }
    }
  if(carry>0){
    Node *temp=new Node;
    temp->data=carry;
    temp->next=head;
    head=temp;
  }
  return head;
}