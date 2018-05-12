
#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
  struct Node *nextRight;
};
void connect(struct Node *p);
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
void printSpecial(Node *root)
{
   if (root == NULL)
     return;
   Node *node = root;
   while (node != NULL)
   {
      printf("%d ", node->data);
      node = node->nextRight;
   }
   if (root->left)
     printSpecial(root->left);
   else
     printSpecial(root->right);
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
  ios::sync_with_stdio(false);
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
     connect(root);
     printSpecial(root);
     printf("\n");
     inorder(root);
     printf("\n");
  }
  return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */
// Should set the nextRight for all nodes
void connect(Node *p)
{
   // Your Code Here
   queue<Node*> q;
   Node* prev;
   q.push(p);
   int size;
   while(!q.empty()){
        size=q.size();
        p=q.front();
        if(p!=NULL){
            if(p->left!=NULL)
                q.push(p->left);
            if(p->right!=NULL)
                q.push(p->right);
            prev=p;
        }
        size--;
        q.pop();
        while(size--){
            p=q.front();
            prev->nextRight=p;
            if(p->left!=NULL)
                q.push(p->left);
            if(p->right!=NULL)
                q.push(p->right);
            prev=p;
            q.pop();
        }
        prev->nextRight=NULL;
    }
}
