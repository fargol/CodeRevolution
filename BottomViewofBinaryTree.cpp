// C++ Program to print Bottom View of Binary Tree
#include<bits/stdc++.h>
using namespace std;
// Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};
Node *newNode(int k)
{
    return new Node(k);
}
// Method that prints the bottom view.
void bottomView(Node *root);
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
     bottomView(root);
     cout << endl;
  }
  return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Tree node class
struct Node
{
    int data; 
    Node *left, *right; 
}; */
// Method that prints the bottom view.
inline void preorder(Node *root,unordered_map<Node*,int> &Node_depth,map<int,Node*> &hm,int depth,int dist){
  if(root!=NULL){
    Node_depth[root]=depth;
    if(hm.find(dist)==hm.end()){
      hm[dist]=root;
    }
    else{
      if(Node_depth[root]>=Node_depth[hm[dist]]){
        hm[dist]=root;
      }
    }
    preorder(root->left,Node_depth,hm,depth+1,dist-1);
    preorder(root->right,Node_depth,hm,depth+1,dist+1);
  }
}
void bottomView(Node *root)
{
   // Your Code Here
  map<int,Node*> hm;
  unordered_map<Node*,int> Node_depth;
  preorder(root,Node_depth,hm,0,0);
  for(auto i=hm.begin();i!=hm.end();i++){
    cout<<i->second->data<<" ";
  }
  cout<<endl;
}