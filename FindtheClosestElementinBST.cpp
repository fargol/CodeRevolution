
#include<bits/stdc++.h>
using namespace std;
struct Node {
int data;
struct Node * right, * left;
};
int maxDiff(Node* , int );
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
int getCountOfNode(Node *root, int l, int h)
{
    if (!root) return 0;
    if (root->data == h && root->data == l)
        return 1;
    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);
    else if (root->data < l)
         return getCountOfNode(root->right, l, h);
    else return getCountOfNode(root->left, l, h);
}
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
        int s;
        cin>>s;
     cout<<maxDiff(root,s);
     cout<<endl;
    }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/
/*You are required to complete below method */
inline void preorder(Node *root,int k,int &val,int &diff){
    int t;
    if(root!=NULL){
        t=abs(k-root->data);
        if(diff>t){
            diff=t;
            val=root->data;
        }
        preorder(root->left,k,val,diff);
        preorder(root->right,k,val,diff);
    }
}
int maxDiff(Node *root, int k)
{
    //Your code here
    int val,diff=INT_MAX;
    preorder(root,k,val,diff);
    return val;
}
