#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	char x;
	cin>>T;
	while(T--){
		cin>>N;
		vector<int> arr(26,0);
		int idx;
		queue<char> Q;
		while(N--){
			cin>>x;
			idx=x-'a';
			arr[idx]++;
			if(arr[idx]==1){
				Q.push(x);
			}
			else{
				while(!Q.empty()&&arr[Q.front()-'a']>1)
					Q.pop();
			}
			if(!Q.empty())
				cout<<Q.front()<<" ";
			else
				cout<<-1<<" ";
		}
		cout<<endl;
	}
}