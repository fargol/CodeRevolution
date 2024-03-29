
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
// A wrapper over rightViewUtil()
void rightView(struct Node *root);
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
     rightView(root);
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
// Should print right view of tree
void rightView(Node *root)
{
   // Your Code here
   queue<Node*> Q1,Q2;
   Node* curr;
   Q1.push(root);
   char ch='1';
   while(1){
       bool flag=false;
       if(ch=='1'){
           if(Q1.empty())
                break;
           while(!Q1.empty()){
               curr=Q1.front();
               if(curr->right!=NULL)
                    Q2.push(curr->right);
                if(curr->left!=NULL)
                    Q2.push(curr->left);
               if(!flag){
                    cout<<curr->data<<" ";
                    flag=true;
               }
                Q1.pop();
           }
           ch='2';
       }
       else if(ch=='2'){
           if(Q2.empty())
                break;
           while(!Q2.empty()){
               curr=Q2.front();
               if(curr->right!=NULL)
                    Q1.push(curr->right);
                if(curr->left!=NULL)
                    Q1.push(curr->left);
               if(!flag){
                    cout<<curr->data<<" ";
                    flag=true;
               }
                Q2.pop();
           }
           ch='1';
       }
   }
}