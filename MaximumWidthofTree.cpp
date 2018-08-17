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
/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
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
     cout << getMaxWidth(root) << endl;
  }
  return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*  Structure of a Binary Tree 
struct Node
{
    int data;
    Node* left, *right;
}; */
/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root)
{
   // Your code here
  Node *curr=root;
  queue<Node*> Q;
  Q.push(curr);
  unordered_map<Node*,int> hm;
  hm[curr]=1;
  int c=0,maxc=INT_MAX,level=1;
  while(!Q.empty()){
    curr=Q.front();
    if(level==hm[curr]){
      c++;
    }
    else{
      if(maxc>c)
        maxc=c;
      c=1;
      level=hm[curr];
    }
    if(curr->left!=NULL){
      Q.push(curr->left);
      hm[curr->left]=hm[curr]+1;
    }
    if(curr->right!=NULL){
      Q.push(curr->right);
      hm[curr->right]=hm[curr]+1;
    }
    Q.pop();
  }
  if(maxc<c)
    maxc=c;
  return maxc;
}
