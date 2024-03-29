#include<bits/stdc++.h>
using namespace std;
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =(struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void convert(node *head,TreeNode * &root);
void lvl (TreeNode *r)
{
    if(r==NULL)
        return;
    queue<TreeNode *> q;
    q.push(r);
    while(!q.empty())
    {
        TreeNode * j = q.front();
        cout<<j->data<<" ";
        q.pop();
        if(j->left)
            q.push(j->left);
        if(j->right)
            q.push(j->right);
    }
}
void reverses(node **head)
{
    node *prev=NULL;
    node *cur = *head;
    node *nxt;
    while(cur!=NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;
    cin>>T;
    while(T--){
    struct node *head = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            push(&head,l);
        }
        reverses(&head);
    TreeNode *root=NULL;
    convert(head,root);
if(root==NULL)
cout<<"-1";
lvl(root);
cout<<endl;
   // inorder(root);
    getchar();
    }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure of Link list node is as follows 
struct node
{
    int data;
    struct node* next;
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/
/*You are required to complete this method*/
void convert(node *head,TreeNode * &root)
{
  //Your code here
    root=NULL;
    node *curr=head;
    queue<TreeNode*> Q;
    root=new TreeNode;
    root->data=curr->data;
    root->left=root->right=NULL;
    Q.push(root);
    curr=curr->next;
    while(!Q.empty()){
        if(curr!=NULL){
            Q.front()->left=new TreeNode;
            Q.front()->left->data=curr->data;
            Q.front()->left->left=Q.front()->left->right=NULL;
            curr=curr->next;
            Q.push(Q.front()->left);
        }
        if(curr!=NULL){
            Q.front()->right=new TreeNode;
            Q.front()->right->data=curr->data;
            Q.front()->right->left=Q.front()->right->right=NULL;
            curr=curr->next;
            Q.push(Q.front()->right);
        }   
        Q.pop();
    }
}
