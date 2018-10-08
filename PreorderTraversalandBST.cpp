#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
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
		cout<<check_for_BST(arr,N)<<endl;
	}
}