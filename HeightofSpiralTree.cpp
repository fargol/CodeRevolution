#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int key;
	Node* left, *right;
};
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}
void saveLeafNodes(Node* root, vector<Node*> &leaf)
{
    if(!root)return;
    saveLeafNodes(root->left, leaf);
    if(root->left==NULL && root->right==NULL)leaf.push_back(root);
    saveLeafNodes(root->right, leaf);
}
void linkLeafNodes(Node* root)
{
    vector<Node*> leaf;
    saveLeafNodes(root, leaf);
    if(leaf.size()<=1)return;
    for(int i=0; i<leaf.size(); i++)
    {
        if(i==0)
        {
            leaf[i]->right=leaf[i+1];
            leaf[i]->left=leaf[leaf.size()-1];
        }
        else if(i==leaf.size()-1)
        {
            leaf[i]->right=leaf[0];
            leaf[i]->left=leaf[i-1];
        }
        else
        {
            leaf[i]->right=leaf[i+1];
            leaf[i]->left=leaf[i-1];
        }
    }
    return;
}
int findTreeHeight(Node* node);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     linkLeafNodes(root);
     cout<<findTreeHeight(root)<<endl;
  }
  return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Structure of the node of the binary tree
struct Node
{
	int key;
	Node* left, *right;
};
*/
// function should return the height of the binary tree
bool isLeaf(Node *node){
  if(node->left!=NULL&&node->right!=NULL){
    if(node->left->right==node&&node->right->left==node)
      return true;
  }
  return false;
}
int getHeight(Node* root){
  if(root==NULL)
    return 0;
  if(isLeaf(root)){
    return 1;
  }
  return (max(getHeight(root->left),getHeight(root->right))+1);
}
int findTreeHeight(Node* node)
{
	// Code here
  return getHeight(node);
}