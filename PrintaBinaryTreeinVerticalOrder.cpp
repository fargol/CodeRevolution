
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
void verticalOrder(Node *root);
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
     verticalOrder(root);
     cout << endl;
  }
  return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/* Should print vertical order such that each vertical line
   is separated by $ */
void preorder(Node* root,map<int,vector<int> > &mp,int d,int &min_d,int &max_d){
    if(root!=NULL){
        if(min_d>d)
            min_d=d;
        if(max_d<d)
            max_d=d;
        mp[d].push_back(root->data);
        preorder(root->left,mp,d-1,min_d,max_d);
        preorder(root->right,mp,d+1,min_d,max_d);
    }
}
void verticalOrder(Node *root)
{
    //Your code here
    int min_d=INT_MAX,max_d=INT_MIN;
    map<int,vector<int> > mp;
    preorder(root,mp,0,min_d,max_d);
    //sort(dist.begin(),dist.end());
    int i;
    for(i=min_d;i<=max_d;i++){
        for(int j=0;j<mp[i].size();j++)
            cout<<mp[i][j]<<" ";
        cout<<'$';
    }
}