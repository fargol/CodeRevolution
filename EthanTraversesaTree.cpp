#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
void preorder_trav(int A[],int B[],int &N,int preorder[]){
	stack<int> st;
	int curr;
	int i=1;
	st.push(1);
	while(!st.empty()){
		curr=st.top();
		preorder[i]=curr;
		i++;
		st.pop();
		if(B[curr]!=0)
			st.push(B[curr]);
		if(A[curr]!=0)
			st.push(A[curr]);
	}
}
void postorder_trav(int A[],int B[],int &N,int postorder[]){
	stack<int> st1,st2;
	int curr;
	int i=1;
	st1.push(1);
	while(!st1.empty()){
		curr=st1.top();
		st1.pop();
		st2.push(curr);
		if(A[curr]!=0)
			st1.push(A[curr]);
		if(B[curr]!=0)
			st1.push(B[curr]);
	}
	while(!st2.empty()){
		curr=st2.top();
		postorder[i]=curr;
		i++;
		st2.pop();
	}
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,K,l,color,id;
	int A[2010],B[2010],L[2010];
	cin>>T;
	int preorder[2010],postorder[2010],preorderIdx[2010],postorderIdx[2010];
	for(int i=1;i<=T;i++){
		scanf("%d %d",&N,&K);
		for(int j=1;j<=N;j++)
			scanf("%d %d",&A[j],&B[j]);
		preorder_trav(A,B,N,preorder);
		postorder_trav(A,B,N,postorder);
		for(int j=1;j<=N;j++)
			preorderIdx[preorder[j]]=j;
		for(int j=1;j<=N;j++)
			postorderIdx[postorder[j]]=j;
		l=0;
		for(int j=0;j<2010;j++)
			L[j]=-1;
		for(int j=1;j<=N;j++){
			if(L[j]==-1){
				id=j;
				L[j]=l%K+1;
				color=l%K+1;
				l++;
				while(L[preorder[postorderIdx[id]]]==-1){
					L[preorder[postorderIdx[id]]]=color;
					id=preorder[postorderIdx[id]];
				}
			}
		}
		/*cout<<"Preorder = \n";
		for(int j=1;j<=N;j++)
			cout<<preorder[j]<<" ";
		cout<<endl;
		cout<<"Postorder = \n";
		for(int j=1;j<=N;j++)
			cout<<postorder[j]<<" ";
		cout<<endl;*/
		if(l<K){
			printf("Case #%d: Impossible\n",i);
		}
		else{
			printf("Case #%d: ",i);
			for(int j=1;j<=N;j++)
				printf("%d ",L[j]);
			printf("\n");
		}
	}
}