#include<bits/stdc++.h>
using namespace std;
/* You would want to remove below 3 lines if your compiler
supports bool, true and false*/
#define bool int
#define true 1
#define false 0
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
int data;
struct node* left;
struct node* right;
};
/* converts a tree to its mrror image */
void mirror(struct node* node);
/* returns true if structure of two trees a and b is same
Only structure is considered for comparison, not data! */
bool isStructSame(struct node *a, struct node *b);
/* Returns true if the given tree is foldable */
bool isFoldable(struct node *root);
/* UTILITY FUNCTIONS */
/* Change a tree so that the roles of the left and
	right pointers are swapped at every node.
	See http://www.geeksforgeeks.org/?p=662 for details */
void mirror(struct node* node)
{
if (node==NULL)
	return;
else
{
	struct node* temp;
	/* do the subtrees */
	mirror(node->left);
	mirror(node->right);
	/* swap the pointers in this node */
	temp	 = node->left;
	node->left = node->right;
	node->right = temp;
}
}
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data)
{
struct node* node = (struct node*)
					malloc(sizeof(struct node));
node->data = data;
node->left = NULL;
node->right = NULL;
return(node);
}
void insert(struct node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->data==n1)
     {
         switch(lr)
         {
          case 'L': root->left=newNode(n2);
                    break;
          case 'R': root->right=newNode(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
/* Driver program to test mirror() */
int main(void)
{
/* The constructed binary tree is
		1
	/ \
	2	 3
	\ /
	4 5
*/
int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct node *root=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=newNode(n1);
            switch(lr){
                    case 'L': root->left=newNode(n2);
                    break;
                    case 'R': root->right=newNode(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
if(isFoldable(root) == 1)
{ cout<<"Yes"<<endl; }
else
{ cout<<"No"<<endl; }
getchar();
    }
return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Returns true if the given tree is foldable */
bool isMirror(node *r1,node *r2){
    if(r1==NULL&&r2==NULL)
        return true;
    if(r1==NULL||r2==NULL)
        return false;
    return (isMirror(r1->left,r2->right)&&isMirror(r1->right,r2->left));
}
bool isFoldable(struct node *root)
{
  // Your code goes here
    if(root==NULL)
        return true;
    return isMirror(root->left,root->right);
}