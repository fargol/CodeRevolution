#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}
struct node* NewNode(int data)
{
    struct node* node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
struct node *correctBST( struct node* root );
void Inorder(struct node *root){
	if(root==NULL){
		return;
	}
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}
int flag=1;
int c=0;
void inorder(struct node *temp,struct node *root){
	if(flag==0){
		return;
	}
	if(temp==NULL&&root==NULL)
		return;
	if(root==NULL){
		flag=0;
		return;
	}
	if(temp==NULL){
		flag=0;
		return;
	}
	if(temp->data==root->data){
	    c++;
	}
	inorder(temp->left,root->left);
	inorder(temp->right,root->right);
}
void insert(struct node *root,int a1,int a2,char lr){
	if(root==NULL)
		return;
	if(root->data==a1){
		switch(lr){
				case 'L':root->left=NewNode(a2);
				break;
				case 'R':root->right=NewNode(a2);
				break;
			}
	}
	insert(root->left,a1,a2,lr);
	insert(root->right,a1,a2,lr);
}
int main()
{   
	int t;
	cin>>t;
	while(t--){
	struct node *root=NULL;
	struct node *temp=NULL;
	int n;
	cin>>n;
	int m=n;
	while(n--){
		int a1,a2;
		char lr;
		cin>>a1>>a2>>lr;
		if(root==NULL){
			temp=NewNode(a1);
			root=NewNode(a1);
			switch(lr){
				case 'L':root->left=NewNode(a2);
				        temp->left=NewNode(a2);
				break;
				case 'R':root->right=NewNode(a2);
				        temp->right=NewNode(a2);
				break;
			}
		}
		else{
			insert(root,a1,a2,lr);
			insert(temp,a1,a2,lr);
		}
	}
	flag=1;
	c=0;
	//Inorder(root);
	//cout<<endl;
	root=correctBST(root);
	//Inorder(root);
	//cout<<endl;
	inorder(temp,root);
	//cout<<c<<endl;
	if(c+1==m){
	    cout<<flag<<endl;
	}
	else{
	    cout<<"0";
	}
	}
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function
node is as follows:
struct node
{
    int data;
    struct node *left, *right;
};
*/
void inorder(node *root,node *&wr1,node *&wr2,node *&wr3,node *&prev){
	if(root==NULL)
		return;
	if(prev!=NULL){
		if(root->data<prev->data){
			if(wr1==NULL){
				wr1=prev;
				wr2=root;
			}
			else if(wr3==NULL){
				wr3=root;
			}
		}
	}
	inorder(root->left,wr1,wr2,wr3,prev);
	prev=root;
	inorder(root->right,wr1,wr2,wr3,prev);
}
void swap(node *a,node *b){
	int temp=a->data;
	a->data=b->data;
	b->data=temp;
}
struct node *correctBST( struct node* root )
{
//add code here.
	node *wr1=NULL,*wr2=NULL,*wr3=NULL,*prev=NULL;
	inorder(root,wr1,wr2,wr3,prev);
	if(wr3==NULL){
		swap(wr1,wr2);
	}
	else{
		swap(wr1,wr3);
	}
	return root;
}