#include<bits/stdc++.h>
using namespace std;
struct Node
{
    struct Node *left, *right;
    int data;
};
Node *bTreeToCList(Node *root);
void displayCList(Node *head)
{
    Node *itr = head;
    do
    {
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);
    cout <<endl;
	itr=itr->left;
	do{
		cout<<itr->data<<" ";
		itr=itr->left;
	}while(head!=itr);
	cout<<itr->data<<endl;
}
Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int main()
{
	int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     Node *root = NULL;
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
        Node *child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
    Node *head = bTreeToCList(root);
    displayCList(head); 
  }
    return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below
Node is as follows:
struct Node
{
    struct Node *left, *right;
    int data;
};*/
void inorder(Node *&head,Node *root,Node *&prev){
  if(root==NULL)
    return;
  inorder(head,root->left,prev);
  if(prev==NULL){
    head=root;
  }
  else{
    root->left=prev;
    prev->right=root;
  }
  prev=root;
  inorder(head,root->right,prev);
}
Node* getTail(Node *root){
  if(root->right==NULL)
    return root;
  else
    return getTail(root->right);
}
Node *bTreeToCList(Node *root)
{
//add code here.
  Node *head=NULL,*prev=NULL,*tail;
  inorder(head,root,prev);
  tail=getTail(root);
  tail->right=head;
  head->left=tail;
  return head;
}