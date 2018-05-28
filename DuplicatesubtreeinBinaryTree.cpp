#include <bits/stdc++.h>
using namespace std;
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};
struct Node* insert(struct Node* root,char data)
{
    if(root==NULL){
    root= new struct Node;
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
    }
    else if(root->data<data)
    root->right=insert(root->right,data);
    else if(root->data>data)
    root->left=insert(root->left,data);
  return root;
}
struct Node* insertString(struct Node* root,string s, int *j)
{
    if((*j)>=s.length())
    return NULL;
	          if(s[*j]=='(')
	          (*j)++;
	         if(s[*j]!='('&&s[*j]!=')'){
	             
	             char n=0;
	             n = s[*j];
             (*j)++;
	          root=insert(root,n);
	          //cout<<"root->data="<<root->data<<endl;
	         // (*j)++;
	          if(s[*j]==')'){
                root->left=NULL;
              root->right=NULL;
              //cout<<"root->data="<<root->data<<endl;
              //cout<<"root->left=NULL";
              //cout<<"root->right=NULL\";
              return root;
	          }
	         }
             if(s[*j]=='(')
	          (*j)++;
	          if(s[*j]==')'){
	            //  cout<<"root->data="<<root->data<<endl;
              //cout<<"root->left=NULL";
	          root->left=NULL;
	          }
              else{
                //    cout<<"root->left->parent->data="<<root->data<<endl;
	          root->left=insertString(root->left,s,j);
              }
//cout<<"right";
              while(s[*j]==')')
	          (*j)++;
	          if(s[*j]=='(')
	          (*j)++;
	          if(s[*j]==')'){
      //        cout<<"root->data="<<root->data<<endl;
        //      cout<<"root->right=NULL";
	          root->right=NULL;
	          (*j)++;
	          }
	          else{
          //    cout<<"root->right->parent->data"<<root->data<<endl;
              root->right=insertString(root->right,s,j);
	          }
return root;
}
void print(struct Node* root)
{
    if(root==NULL)
        return;
    print (root->left);
    cout<<root->data<<endl;
    print(root->right);
}
bool dupSub(Node *root);
int main() {
	//code
	int i,j,k,T ,level;
	char s[500];
	   cin>>T;
	   for(i=0;i<T;i++)
	   {
	     // cin>>level;
	      cin>>s;
	      int j=0;
	      struct Node* root=NULL;
	      root=insertString(root,s,&j);
	   
        cout<<dupSub(root)<<endl;
	  
	   }
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/
/*This function returns true if the tree contains 
a duplicate subtree of size 2 or more else returns false*/
void preorder(Node* root, vector<string> &arr){
    if(root!=NULL){
        string s(1,root->data);
        arr.push_back(s);
        preorder(root->left,arr);
        preorder(root->right,arr);
    }
}
bool dupSub(Node *root)
{
     //your code here
     vector<string> arr;
     preorder(root,arr);
     /*for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";*/
    //cout<<endl;
     string s1,s2;
     for(int i=0;i<arr.size()-2;i++){
         s1=arr[i];
         s1+=arr[i+1];
         s1+=arr[i+2];
         for(int j=i+3;j<arr.size()-2;j++){
             s2=arr[j];
             s2+=arr[j+1];
             s2+=arr[j+2];
             //cout<<"s1 = "<<s1<<endl;
             //cout<<"s2 = "<<s2<<endl;
             if(s1==s2)
                return true;
         }
     }
     return false;
}