#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
void printLeafNodes(int arr[],int N){
	if(N==1){
		cout<<arr[0]<<endl;
		return;
	}
	stack<int> st;
	bool marker[N];
	memset(marker,false,N*sizeof(marker[0]));
	int root=0;
	st.push(0);
	marker[0]=true;
	for(int i=1;i<N;i++){
		root=-1;
		while(!st.empty()&&arr[st.top()]<arr[i]){
			root=st.top();
			st.pop();
		}
		if(root!=-1){
			marker[root]=true;
		}
		else{
			marker[st.top()]=true;
		}
		st.push(i);
	}
	for(int i=0;i<N;i++){
		if(!marker[i])
			cout<<arr[i]<<" ";
	}
	cout<<endl;
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
		printLeafNodes(arr,N);
	}
}