#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
struct Node* newNode (int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void printInorder (struct Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder (node->right);
}
Node* constructTree(int n, int pre[], char preLN[]);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* root = NULL;
        int n;
        cin>>n;
        int pre[n];
        char preLN[n];
        for(int i=0; i<n; i++)cin>>pre[i];
        for(int i=0; i<n; i++)cin>>preLN[i];
        root = constructTree (n, pre, preLN);
        printInorder(root);
        cout<<endl;
    }
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed
void createTree(int pre[],char preLN[],int size,Node *root,int &idx){
	if(idx<size){
		Node *curr;
		root->left=new Node;
		curr=root->left;
		curr->data=pre[idx];
		curr->left=NULL;
		curr->right=NULL;
		if(preLN[idx]!='L'){
			idx++;
			createTree(pre,preLN,size,curr,idx);
		}
		idx++;
		if(idx<size){
			root->right=new Node;
			curr=root->right;
			curr->data=pre[idx];
			curr->left=NULL;
			curr->right=NULL;
			if(preLN[idx]!='L'){
				idx++;
				createTree(pre,preLN,size,root->right,idx);
			}
		}
	}
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    int idx=0;
    Node *root;
    root=new Node;
    root->data=pre[idx];
    root->left=root->right=NULL;
    if(preLN[idx]!='L'){
    	idx++;
    	createTree(pre,preLN,n,root,idx);
    }
    return root;
}