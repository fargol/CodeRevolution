// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;
// BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
int key=0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);
// A utility function to create a new BST node
Node *newNode(int item)
{
	Node *temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
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
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    Node *pre=NULL;
    Node *suc=NULL;
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
   // Inorder(root);
    //Node * target =ptr;
    //printkdistanceNode(root, target, k);
    //cout<<endl;
    cin>>key;
    findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << pre->key;
	else
	cout << "-1";
	if (suc != NULL)
	cout <<" "<<suc->key<<endl;
	else
	cout << " "<<"-1"<<endl;
    }
	return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
Node* findKey(Node *root,int key){
    if(root==NULL)
        return NULL;
    if(root->key==key)
        return root;
    if(root->key<key)
        return findKey(root->right,key);
    return findKey(root->left,key);
}
void findUtil(Node *root,int key,Node *&pre,Node *&suc){
    if(root!=NULL){
        if(key<root->key){
            suc=root;
            findUtil(root->left,key,pre,suc);
        }
        else if(key==root->key){
            findUtil(root->left,key,pre,suc);
            findUtil(root->right,key,pre,suc);
        }
        else{
            pre=root;
            findUtil(root->right,key,pre,suc);
        }
    }
}
Node* insert(Node *&root,int key){
    if(root==NULL){
        root=new Node;
        root->key=key;
        root->left=root->right=NULL;
        return root;
    }
    else{
        if(root->key<key)
            return insert(root->right,key);
        else
            return insert(root->left,key);
    }
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
// Your code goes here
    Node *ele=findKey(root,key);
    if(ele!=NULL){
        //cout<<"Yes\n";
        findUtil(root,key,pre,suc);
    }
    else{
        //cout<<"NO\n";
        ele=insert(root,key);
        findUtil(root,key,pre,suc);
    }
}