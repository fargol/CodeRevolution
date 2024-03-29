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
 void reorderList(struct Node *head) ;
/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}
void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    //printf("");
}
void freeList(struct Node *head)
{
	struct Node* temp;
    while(head != NULL)
    {
        
        temp=head;
        head = head->next;
        free(temp);
    }
  
}
int main(void)
{
   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {
	   struct Node* temp,*head;
	    cin>>n;
	    cin>>x;
	    head=newNode(x);
	    temp=head;
	    for(i=0;i<n-1;i++)
	    {
			cin>>x;
			temp->next=newNode(x);
			temp=temp->next;
			}
	   
		reorderList(head);
	    printList(head);
freeList(head);
   }
   return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Following is the Linked list node structure */
/*struct Node
{
    int data;
    Node* next;
};*/
void util(Node *&head,Node *curr,bool &flag){
  if(curr==NULL)
    return;
  util(head,curr->next,flag);
    if(!flag&&(head==curr||head->next==curr)){
      curr->next=NULL;
      flag=true;
      return;
    }
    if(!flag){
      curr->next=head->next;
      head->next=curr;
      head=curr->next;
    }
}
void reorderList(Node *head) 
{
    // Your code here
    Node *head1=head;
    bool flag=false;
    util(head1,head,flag);
}