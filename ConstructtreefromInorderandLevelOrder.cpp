#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node* left, *right;
};
Node* newNode(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}
Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
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
    int key;
    struct Node* left, *right;
};
*/
void util(Node *&root,unordered_map<int,int> &hm,int val){
    /*if(!(in_beg<=in_end&&lev_beg<=lev_end))
        return;*/
    if(root==NULL){
        root=new Node;
        root->key=val;
        root->left=root->right=NULL;
    }
    else{
        if(hm[val]<hm[root->key])
            util(root->left,hm,val);
        else
            util(root->right,hm,val);
    }
}
Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
//add code here.
    Node *root=NULL;
    unordered_map<int,int> hm;
    for(int i=0;i<n;i++)
        hm[inorder[i]]=i;
    for(int i=0;i<n;i++){
        util(root,hm,levelOrder[i]);
    }
    return root;
}