#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++){
			cin>>arr[i];
		}
		stack<int> st;
		int next_smaller[N];
		next_smaller[N-1]=-1;
		st.push(arr[N-1]);
		for(int i=N-2;i>=0;i--){
			while(!st.empty()&&st.top()>=arr[i])
				st.pop();
			if(!st.empty()){
				next_smaller[i]=st.top();
			}
			else{
				next_smaller[i]=-1;
			}
			st.push(arr[i]);
		}
		for(int i=0;i<N;i++)
			cout<<next_smaller[i]<<" ";
		cout<<endl;
	}
}