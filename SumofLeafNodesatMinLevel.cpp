//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
int minLeafSum(Node* root);
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
     cout<<minLeafSum(root)<<endl;
  }
  return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++
/*
Structure of the Node of the tree is 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};*/
// Your task is to complete this function
// function shoudl return the required sum
bool isLeaf(Node *root){
  if(root==NULL){
    return false;
  }
  if(root->left==NULL&&root->right==NULL){
    return true;
  }
  return false;
}
void inorder(Node *root,int &min_level,int &res,int curr_level){
  if(root==NULL){
    return;
  }
  if(isLeaf(root)){
    if(min_level>curr_level){
      min_level=curr_level;
      res=root->data;
    }
    else if(min_level==curr_level){
      res+=root->data;
    }
  }
  else{
    inorder(root->left,min_level,res,curr_level+1);
    inorder(root->right,min_level,res,curr_level+1);
  }
}
int minLeafSum(Node* root)
{
	// Code here
  int min_level=INT_MAX,res=0;
  inorder(root,min_level,res,0);
  return res;
}