
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
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
int maxDiff(Node *root);
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
   cout<<maxDiff(root)<<endl;
 }
  return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/* Your are required to 
complete this method*/
void preorder(Node *root,int &max_diff,int max_ances){
    int diff;
    if(max_ances<root->data)
        max_ances=root->data;
    if(root->left!=NULL){
        diff=max_ances-root->left->data;
        if(max_diff<diff)
            max_diff=diff;
        preorder(root->left,max_diff,max_ances);
    }
    if(root->right!=NULL){
        diff=max_ances-root->right->data;
        if(max_diff<diff)
            max_diff=diff;
        preorder(root->right,max_diff,max_ances);
    }
}
int maxDiff(Node* root)
{
    // Your code here 
    int max_diff=INT_MIN;
    int max_ances=INT_MIN;
    preorder(root,max_diff,max_ances);
    return max_diff;
}