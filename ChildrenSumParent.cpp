#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left,*right;
};
Node *newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
 
    return (temp);
}
void insert(Node *root,int a1,int a2,char lr){
	if(root==NULL){
		return;
	}
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=newNode(a2);
			break;
			case 'R':root->right=newNode(a2);
			break;
		}
	}
	else{
		insert(root->left,a1,a2,lr);
		insert(root->right,a1,a2,lr);
	}
}
void inorder(Node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int isSumProperty(Node *node);
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t-->0)
	{
		int n;
		cin>>n;
		int m=n;
		Node *root1=NULL;
		while(n-->0){
			int a1,a2;
			cin>>a1>>a2;
			char lr;
			scanf(" %c",&lr);
			if(root1==NULL){
				root1=newNode(a1);
				switch(lr){
					case 'L':root1->left=newNode(a2);
					break;
					case 'R':root1->right=newNode(a2);
					break;
				}
			}
			else{
				insert(root1,a1,a2,lr);
			}
		}
			cout<<isSumProperty(root1)<<"
";
	}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
};
*/
int isSumProperty(Node *node)
{
 // Add your code here
 if(node!=NULL){
    int s=0;
    if(node->left!=NULL)
        s+=node->left->data;
    if(node->right!=NULL)
        s+=node->right->data;
    if(s==node->data||s==0)
        return (isSumProperty(node->left)&&isSumProperty(node->right));
    else
        return 0;
 }
 else
    return 1;
}
