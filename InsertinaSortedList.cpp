#include<iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
void sortedInsert(struct node** head_ref, int data);
struct node *newNode(int new_data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = NULL;
	return new_node;
}
void append(struct node** headRef, int newData)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	struct node *last = *headRef;
	new_node->data = newData;
	new_node->next = NULL;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)last = last->next;
	last->next = new_node;
}
void printList(struct node *head)
{
	struct node *temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<' ';
		temp = temp->next;
	}
	cout<<endl;
}
/* Drier program to test count function*/
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct node* head = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, k);
	    }
	    cin>>k;
	    sortedInsert(&head, k);
	    printList(head);
	}
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
structure of the node of the list is as
struct node
{
	int data;
	struct node* next;
};
*/
void sortedInsert(struct node** head_ref, int data)
{
    // Code here
    node **head=head_ref;
    node *curr=*head,*prev=NULL;
    while(curr!=NULL&&curr->data<data){
    	prev=curr;
    	curr=curr->next;
    }
    if(prev!=NULL){
    	node *temp=new node;
    	temp->next=curr;
    	temp->data=data;
    	prev->next=temp;
    }
    else{
    	(*head)=new node;
    	(*head)->data=data;
    	(*head)->next=curr;
    }
}
