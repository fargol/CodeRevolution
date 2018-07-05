#include<bits/stdc++.h>
using namespace std;
/* Link list node */
struct node *reverse (struct node *head, int k);
struct node
{
    int data;
    struct node* next;
}*head;
/* UTILITY FUNCTIONS */
/* Function to push a node */
  void insert()
{
    int n,value;
    cin>>n;
    struct node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            head=(struct node *) malloc( sizeof(struct node) );
            head->data=value;
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= (struct node *) malloc( sizeof(struct node) );
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}
/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
printf("%c",'\0');
}
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    int t,k,value,n;
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     cin>>t;
     while(t--)
     {
     insert();
     cin>>k;
     head = reverse(head, k);
     printList(head);
     }
     return(0);
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
  struct node
  {
     int data;
     struct Node *next;
  }
*/
struct node *reverse (struct node *head, int k)
{ 
  // Complete this method
  stack<node*> arr;
  node* curr=head,*prev=NULL,*pres=head;
  int c,f=0;
  while(pres!=NULL){
      c=0;
      while(c!=k){
          arr.push(pres);
          if(pres!=NULL)
            pres=pres->next;
          c++;
      }
      curr=arr.top();
      if(prev!=NULL)
        prev->next=curr;
      if(f==0){
        head=arr.top();
        f=1;
      }
      arr.pop();
      while(!arr.empty()){
          if(curr!=NULL){
            curr->next=arr.top();
            curr=curr->next;
          }
          arr.pop();
      }
      prev=curr;
  }
  if(prev!=NULL)
  	prev->next=NULL;
  /*if(curr==NULL)
  	cout<<"Yes";
  cout<<curr->data<<"\nPrinting List:- \n"<<endl;
  while(curr!=NULL){
  	cout<<curr->data<<" ";
  	curr=curr->next;
  }*/
  return head;
}
