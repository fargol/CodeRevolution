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
    { insert(&(*tree)->left, val);}
    else if(val > (*tree)->data)
    { insert(&(*tree)->right, val);}
}
void merge(Node *root1,Node *root2);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root1;Node *root2;
        Node *tmp;
        root1 = NULL;
        root2=NULL;
        int N;
        cin>>N;
        int M;
        cin>>M;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root1, k);}
        for(int i=0;i<M;i++)
        {
            int k;
            cin>>k;
            insert(&root2, k);} 
        cout<<"here\n";
       merge(root1,root2);
        cout<<endl;
    }
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The structure of Node is
struct Node {
int data;
Node * right, * left;
};*/
/*You are required to complete below method */
void insert(Node *&root,int key){
    if(root==NULL){
        root=new Node;
        root->data=key;
        root->left=root->right=NULL;
    }
    else if(root->data>key){
        insert(root->left,key);
    }
    else{
        insert(root->right,key);
    }
}
void mergeUtil(Node *root1,Node *root2){
    if(root2==NULL)
        return;
    insert(root1,root2->data);
    mergeUtil(root1,root2->left);
    mergeUtil(root1,root2->right);
}
void inorder(Node *root1){
    if(root1==NULL)
        return;
    inorder(root1->left);
    cout<<root1->data<<" ";
    inorder(root1->right);
}
void merge(Node *root1, Node *root2)
{
   //Your code here
    mergeUtil(root1,root2);
    inorder(root1);
    cout<<endl;
}