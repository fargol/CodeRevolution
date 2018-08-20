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
int findDist(Node* ,int ,int );
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
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
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
     int a,b;
     cin>>a>>b;
     cout<<findDist(root,a,b)<<endl;
  }
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
/* Should return minimum distance between a and b 
   in a tree with given root*/
Node* LCA(Node* root ,int n1 ,int n2 )
{
   //Your code here
    if(root==NULL)
      return NULL;
    if(root->data==n1||root->data==n2)
      return root;
    Node *leftLCA=LCA(root->left,n1,n2);
    Node *rigthLCA=LCA(root->right,n1,n2);
    if(leftLCA&&rigthLCA){
      return root;
    }
    else{
      return leftLCA?leftLCA:rigthLCA;
    }
}
inline void dist(Node *root,int a){
  if(root==NULL)
    return INT_MIN;
  if(root->data==a)
    return 0;
  int ld=dist(root->left,a)+1;
  int rd=dist(root->rigth,a)+1;
  return max(ld,rd);
}
int findDist(Node* root, int a, int b)
{
    // Your code here 
    Node *lca=LCA(root,a,b);
    int distLCA=0,distA=0,distB=0;
    distLCA=getDist(root,lca->data);
    distA=getDist(root,a);
    distB=getDist(root,b);
    return (distA+distB-2*distLCA);
}