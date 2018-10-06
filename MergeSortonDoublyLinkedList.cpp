#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *next, *prev;
};
// Split a doubly linked list (DLL) into 2 DLLs of
// half sizes
struct node *splitList(struct node *head);
// Function to merge two DLLs
struct node *merge(struct node *first, struct node *second);
struct node *mergeSort(struct node *head)
{
	if (!head || !head->next)
		return head;
	struct node *second = splitList(head);
	head = mergeSort(head);
	second = mergeSort(second);
	return merge(head, second);
}
void insert(struct node **head, int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = temp->prev = NULL;
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}
void print(struct node *head)
{
	struct node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}
// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}
// Driver program
int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = mergeSort(head);
        print(head);
    }
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
Structure of the node of the list is as
struct node
{
	int data;
	struct node *next, *prev;
};
*/
// Split a doubly linked list (DLL) into 2 DLLs of
// half sizes
struct node *splitList(struct node *head)
{
    // Code here
    node *slow=head,*fast=head;
    while(fast!=NULL){
    	slow=slow->next;
    	fast=fast->next;
    	if(fast==NULL)
    		break;
    	fast=fast->next;
    }
    slow->prev->next=NULL;
    slow->prev=NULL;
    return slow;
}
// Function to merge two DLLs
struct node *merge(struct node *first, struct node *second)
{
    // Code here
    node *head=NULL,*prev=NULL;
    node *ptr1=first,*ptr2=second;
    if(ptr1->data<=ptr2->data){
    	head=ptr1;
    	prev=ptr1;
    	ptr1=ptr1->next;
    }
    else{
    	head=ptr2;
    	prev=ptr2;
    	ptr2=ptr2->next;
    }
    while(ptr1!=NULL&&ptr2!=NULL){
    	if(ptr1->data<=ptr2->data){
    		prev->next=ptr1;
    		ptr1->prev=prev;
	    	prev=ptr1;
	    	ptr1=ptr1->next;
	    }
	    else{
	    	prev->next=ptr2;
    		ptr2->prev=prev;
	    	prev=ptr2;
	    	ptr2=ptr2->next;
	    }
    }
    while(ptr1!=NULL){
    	prev->next=ptr1;
    	ptr1->prev=prev;
    	prev=ptr1;
    	ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
    	prev->next=ptr2;
    	ptr2->prev=prev;
    	prev=ptr2;
    	ptr2=ptr2->next;
    }
    return head;
}