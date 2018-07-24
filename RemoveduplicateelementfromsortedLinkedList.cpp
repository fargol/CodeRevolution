{
//Code by Shubham Joshi
#include <bits/stdc++.h>
using namespace std;
struct Node
{
int data;
Node* next;
};
Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
                Node *temp = head;
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=newNode(data);
			else
			{
				temp->next = newNode(data);
				temp=temp->next;
			}
		}
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of linked list is the following
struct Node
{
int data;
Node* next;
};*/
Node *removeDuplicates(Node *root)
{
 // your code goes here
    queue<Node*> Q;
 	Node *curr, *prev;
 	stack<Node*> bin;
 	Q.push(root);
    curr=root->next;
 	while(curr!=NULL){
 	    prev=Q.back();
 		if(curr->data!=prev->data){
 			Q.push(curr);
 		}
 		else{
 			bin.push(curr);
 		}
 		curr=curr->next;
 	}
 	root=Q.front();
 	Q.pop();
 	Q.back()->next=NULL;
 	prev=root;
 	while(!Q.empty()){
 	    prev->next=Q.front();
 	    prev=Q.front();
 	    Q.pop();
 	}
 	prev->next=NULL;
 	while(!bin.empty()){
 		curr=bin.top();
 		free(curr);
 		bin.pop();
 	}
 	return root;
}
