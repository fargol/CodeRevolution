//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node *left, *right;
};
// function to get a new node
Node* getNode(int data)
{
	Node *newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL; 
	return newNode;
}
void inorderTraversal(Node* root)
{
	if (!root)return;
	inorderTraversal(root->left);
	cout << root->data << " ";
	inorderTraversal(root->right); 
}
// you need to complete this function
Node* constructBst(int arr[], int n);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        inorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++
/*
Structure of the Node of the node of the bst 
should be as
struct Node
{
	int data;
	Node *left, *right;
};
*/
// You are required to complete this function
void createBST(Node *&root,int data){
	if(root==NULL){
		root=new Node;
		root->data=data;
		root->left=root->right=NULL;
	}
	else if(data<root->data)
		createBST(root->left,data);
	else
		createBST(root->right,data);
}
Node* constructBst(int arr[], int n)
{
    if(n==0)return NULL;
    // Code here
    Node *root=NULL;
    for(int i=0;i<n;i++)
    	createBST(root,arr[i]);
	return root;
}
