#include<bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;
};
static void reverse(struct Node** head_ref)
{
    struct Node* prev   = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
 
/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}
 
/* Function to insert a Node at the beginning of the Doubly Linked List */
void push(struct Node** head_ref, int new_data)
{
    /* allocate Node */
    struct Node* new_Node = newNode(new_data);
 
    /* link the old list off the new Node */
    new_Node->next = (*head_ref);
 
    /* move the head to point to the new Node */
    (*head_ref)    = new_Node;
}
 
 
// A utility function to print a linked list
void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("");
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
Node * mergeKList(Node *arr[],int );
/* Driver program to test above function */
int main(void)
{
   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {
	  
	   int N;
	   cin>>N;
       struct Node **arr = new Node *[N];
       for(int j=0;j<N;j++){
	    cin>>n; 
		    for(i=0;i<n;i++)
	    	{
			cin>>x;
			push(&arr[j], x);
			}
			reverse(&arr[j]);
		   // printList(arr[j]);
   		}
   		
   		Node *res = mergeKList(arr,N);
		printList(res);
		
	 
   }
   return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Linked list Node structure
struct Node
{
    int data;
    Node* next;
};*/ 
/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
struct compare{
bool operator()(Node* a,Node *b)
{
  return a->data>b->data;
}};
Node * mergeKList(Node *arr[], int N)
{
       // Your code here
  priority_queue<Node*,vector<Node*>,compare> Q;
  Node *head=NULL,*curr;
  for(int i=0;i<N;i++){
    Q.push(arr[i]);
  }
  head=Q.top();
  Q.pop();
  curr=head;
  if(curr->next!=NULL)
      Q.push(curr->next);
    //cout<<"11here\n"<<endl;
  while(!Q.empty()){
    //cout<<"data = "<<Q.top()->data<<endl;
    curr->next=Q.top();
    Q.pop();
    curr=curr->next;
    if(curr->next!=NULL)
      Q.push(curr->next);
  }
  //cout<<"here\n"<<endl;
  //curr=curr->next;
  curr->next=NULL;
  return head;
}