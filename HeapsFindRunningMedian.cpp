#include <bits/stdc++.h>

using namespace std;
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}NODE;

typedef NODE* NODEPTR;

void ct(NODEPTR &root, int val){
    if(root!=NULL){
        if(val<root->data)
            ct(root->left,val);
        else
            ct(root->right,val);
    }
    else{
        root=(NODEPTR)malloc(sizeof(NODE));
        //if(root==NULL)
            //cout<<"YES\n";
        root->data=val;
        //cout<<"node: "<<root->data<<endl;
        root->left=NULL;
        root->right=NULL;
    }
}
void inorder(NODEPTR root, vector<int> &v){
    //cout<<"here\n";
    if(root!=NULL){
        inorder(root->left,v);
        cout<<root->data<<endl;
        //v.push_back(root->data);
        inorder(root->right,v);
        //cout<<"v.size ::"<<v.size()<<endl;
    }
    
}
int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(n);

    /*int a_item;
        cin >> a_item;
    NODEPTR root=(NODEPTR)malloc(sizeof(NODE));
    root->data=a_item;
    root->left=NULL;
    root->right=NULL;*/
     vector<int> v;
    NODEPTR root=NULL;
    for (int i = 0; i < n; i++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        ct(root,a_item);
        /*if(root==NULL)
        cout<<"YES\n";*/
        //inorder(root,v);
        //float med;
        //cout<<"v.size ::"<<v.size()<<endl;
        /*if(v.size()&1)
            med=v[v.size()/2];
        else
            med=(v[v.size()/2]+v[v.size()/2-1])/2.0;
        printf("%.1f\n",med);
        for(int j=0;j<v.size();j++)
            cout<<v[j]<<" ";
        cout<<endl;
        v.clear();*/
    }
    /*if(root==NULL)
        cout<<"YES\n";*/
    inorder(root,v);
    return 0;
}
