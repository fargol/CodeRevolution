#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	int arr[1000];
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>arr[i];
		}
		arr[N]=-1;
		stack<int> st;
		st.push(arr[0]);
		int minIdx=0;
		bool flag=false;
		for(int i=1;i<=N;i++){
			if(arr[i]>st.top())
				st.push(arr[i]);
			else{
				st.pop();
				st.push(arr[i]);
				if(minIdx!=i-1){
					flag=true;
					cout<<"("<<minIdx<<" "<<i-1<<") ";
				}
				minIdx=i;
			}
		}
		if(!flag)
			cout<<"No Profit";
		cout<<endl;
	}
}