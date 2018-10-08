#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
struct NODE{
	int key;
	NODE *left,*right;
};
NODE* create_BST(int arr[],int N){
	stack<NODE*> st;
	NODE *root=new NODE;
	root->key=arr[0];
	root->left=root->right=NULL;
	st.push(root);
	NODE *temp,*curr;
	for(int i=1;i<N;i++){
		curr=new NODE;
		curr->key=arr[i];
		curr->left=curr->right=NULL;
		temp=NULL;
		while(!st.empty()&&st.top()->key<arr[i]){
			temp=st.top();
			st.pop();
		}
		if(temp!=NULL){
			temp->right=curr;
		}
		else{
			st.top()->left=curr;
		}
		st.push(curr);
	}
	return root;
}
void postorder(NODE *root){
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->key<<" ";
}
bool check_for_BST(int arr[],int N){
	stack<int> st;
	int root=INT_MIN;
	for(int i=0;i<N;i++){
		if(arr[i]<root)
			return false;
		while(!st.empty()&&st.top()<arr[i]){
			root=st.top();
			st.pop();
		}
		st.push(arr[i]);
	}
	return true;
}
int main(){
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		int arr[N];
		for(int &i:arr)
			cin>>i;
		if(check_for_BST(arr,N)){
			NODE *root=create_BST(arr,N);
			postorder(root);
			cout<<endl;
		}
		else
			cout<<"NO\n";
	}
}