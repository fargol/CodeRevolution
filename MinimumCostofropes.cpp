#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,L[1000];
	cin>>T;
	while(T--){
		cin>>N;
		priority_queue<int,vector<int>,greater<int> > min_heap;
		for(int i=0;i<N;i++){
			cin>>L[i];
			min_heap.push(L[i]);
		}
		int cost=0;
		while(min_heap.size()>1){
			int t1=min_heap.top();
			min_heap.pop();
			int t2=min_heap.top();
			min_heap.pop();
			cost+=t1;
			cost+=t2;
			min_heap.push(t1+t2);
		}
		cout<<cost<<endl;
	}		
}