#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);    
}
int largestBst(Node *root);
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
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
    cout<<largestBst(root)<< endl;
  }
  return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     struct Node* left, *right;
};*/
/*You are required to complete this method */
typedef struct{
  bool isBST;
  int max;
  int min;
  int max_size;
  int size;
}Info;

inline bool isLeaf(Node *node){
  if(node!=NULL&&node->left==NULL&&node->right==NULL)
    return true;
  return false;
}

inline Info BSTutil(Node *root){
  if(root==NULL)
    return {true,INT_MIN,INT_MAX,0,0};
  if(isLeaf(root)){
    return {true,root->data,root->data,1,1};
  }
  Info l=BSTutil(root->left);
  Info r=BSTutil(root->right);
  Info res;
  res.size=l.size+r.size+1;
  if(l.isBST&&r.isBST){
    if(root->data>=l.max&&root->data<=r.min){
      res.max_size=l.max_size+r.max_size+1;
      res.min=min(min(root->data,l.min),r.min);
      res.max=max(max(root->data,l.max),r.max);
      res.isBST=true;
      return res;
    }
  }
  res.max_size=max(l.max_size,r.max_size);
  res.isBST=false;
  return res;
} 
int largestBst(Node *root)
{
	//Your code here
  Info res=BSTutil(root);
  return res.max_size;
}