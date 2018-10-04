#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node* left;
  Node* right;
};
Node* newNode(int data)
{
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
Node *buildTree(int a[],int b[],int str,int end);
int preIndex=0;
void printPostOrder(Node *root){
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		preIndex=0;
		Node *root=NULL;
		int a[n],b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		root=buildTree(a,b,0,n-1);
		printPostOrder(root);
		cout<<endl;
	}
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
void util(Node *&root,int in[],int pre[],int in_beg,int in_end,
	int pre_beg,int pre_end){
	if(!(in_beg<=in_end&&pre_beg<=pre_end))
		return;
	root=new Node;
	root->data=pre[pre_beg];
	root->left=root->right=NULL;
	int id=in_beg;
	while(id<=in_end){
		if(in[id]==root->data)
			break;
		id++;
	}
	int l_size=id-in_beg;
	util(root->left,in,pre,in_beg,id-1,pre_beg+1,pre_beg+l_size);
	util(root->right,in,pre,id+1,in_end,pre_beg+l_size+1,pre_end);
}
Node* buildTree(int in[],int pre[], int inStrt, int inEnd)
{
//add code here.
	Node *root;
	util(root,in,pre,inStrt,inEnd,inStrt,inEnd);
	return root;
}