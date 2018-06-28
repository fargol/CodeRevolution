#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;\\\\\\\,f,fe,fef,pwe,fwe,fpfpewfkpemf
};
int minDepth(Node *node);efefffffffffffffffffffffffffff
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{dwwwwwwwwwwwwwcewwwwwwwwwwwwwwffffewwwwwwwwwwwwwf
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
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d
",&n);
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
    cout<<minDepth(root)<<endl;
    // cout << endl;
  }
  return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*You are required to complete this method*/
void inorder(Node* node, int count, int* min){
    if(node!=NULL){
        inorder(node->left,count+1,min);
        inorder(node->right,count+1,min);
    }
    else{
        if(*min>count)
            *min=count;
    }
}
int minDepth(Node *node)
{
    //Your code here
    int count=0;
    int min=INT_MAX;
    inorder(node,0,&min);
    return min;
}
 