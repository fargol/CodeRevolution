//Code by 1shubhamjoshi1
#include<bits/stdc++.h>
using namespace std;
struct Node {
int data;
struct Node * right, * left;
};
void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }
    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}
void inorderrrrr(Node *root)
{
    if(root!=NULL)
    {
    inorderrrrr(root->left);
    cout<<root->data<< " ";
    inorderrrrr(root->right);
    }
}
void modify(Node **root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;
        root = NULL;
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);
        }
        modify(&root);
        inorderrrrr(root);
        cout<<endl;
    }
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* BST Node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/*  modifies the root of the bst */
void modifyUtil(Node *root,int &sum){
    if(root==NULL)
        return;
    modifyUtil(root->right,sum);
    root->data+=sum;
    sum=root->data;
    modifyUtil(root->left,sum);
}
void modify(Node **root)
{
// Your code here
    int sum=0;
    modifyUtil(*root,sum);
}