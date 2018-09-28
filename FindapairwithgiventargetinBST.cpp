#include <bits/stdc++.h>
#define MAX_SIZE 100
using namespace std;
struct node
{
    int val;
    struct node *left, *right;
};
bool isPairPresent(struct node *root, int target);
struct node * NewNode(int val)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->val = val;
    tmp->right = tmp->left =NULL;
    return tmp;
}
struct node *insert(struct node *root,int a){
	if(root==NULL)
		return NewNode(a);
	if(root->val>a){
		root->left=insert(root->left,a);
	}
	if(root->val<a){
		root->right=insert(root->right,a);
	}
	return root;
}
void inorder(struct node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,target;
		cin>>n>>target;
		struct node *root =  NULL;
		while(n--){
			int a;
			cin>>a;
			if(root==NULL){
				root=NewNode(a);
			}
			else{
				insert(root,a);
			}
		}
		//inorder(root);
    cout<<isPairPresent(root, target)<<endl;
	}
    return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below
node is as follows
struct node
{
    int val;
    struct node *left, *right;
};
*/
bool isPairPresent(struct node *root, int target)
{
//add code here.
	stack<node*> s1,s2;
	node *c1=root,*c2=root;
	while(true){
		s1.push(c1);
		if(c1->left==NULL)
			break;
		c1=c1->left;
	}
	while(true){
		s2.push(c2);
		if(c2->right==NULL)
			break;
		c2=c2->right;
	}
	while(!s1.empty()&&!s2.empty()){
		c1=s1.top();
		c2=s2.top();
		if(c1!=c2&&(c1->val+c2->val)==target)
			return true;
		else if(c1->val+c2->val>target){
			s2.pop();
			if(c2->left!=NULL){
				c2=c2->left;
				while(true){
					s2.push(c2);
					if(c2->right==NULL)
						break;
					c2=c2->right;
				}
			}
		}
		else{
			s1.pop();
			if(c1->right!=NULL){
				c1=c1->right;
				while(true){
					s1.push(c1);
					if(c1->left==NULL)
						break;
					c1=c1->left;
				}
			}
		}
	}
	return false;
}