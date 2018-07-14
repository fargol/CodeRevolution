#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,N;
	cin>>T;
	vector<int> stock(200);
	vector<int> span(200);
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>stock[i];
		span[0]=1;
		stack<int> st;
		st.push(0);
		for(int i=1;i<N;i++){
			while(!st.empty()&&stock[st.top()]<=stock[i])
				st.pop();
			span[i]=st.empty()?(i+1):(i-st.top());
			st.push(i);
		}
		for(int i=0;i<N;i++)
			cout<<span[i]<<" ";
		cout<<endl;
	}
}