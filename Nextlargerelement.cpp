#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		vector<int> arr(N);
		vector<int> next(N);
		for(int i=0;i<N;i++)
			cin>>arr[i];
		next[N-1]=-1;
		stack<int> st;
		st.push(arr[N-1]);
		for(int i=N-2;i>=0;i--){
			while(!st.empty()&&st.top()<=arr[i])
				st.pop();
			next[i]=(st.empty())?(-1):(st.top());
			//cout<<next[i]<<endl;
			st.push(arr[i]);
		}
		for(int i=0;i<N;i++)
			cout<<next[i]<<" ";
		cout<<endl;
	}
}