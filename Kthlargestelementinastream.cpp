#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,K,N,e;
	cin>>T;
	while(T--){
		cin>>K>>N;
		priority_queue<int,vector<int>,greater<int> > minHeap;
		priority_queue<int> maxHeap;
		for(int i=1;i<=N;i++){
			cin>>e;
			if(minHeap.size()<K-1){
				minHeap.push(e);
			}
			else{
				if(!minHeap.empty()&&e>minHeap.top()){
					maxHeap.push(minHeap.top());
					minHeap.pop();
					minHeap.push(e);
				}
				else{
					maxHeap.push(e);
				}
			}
			if(!maxHeap.empty())
				cout<<maxHeap.top()<<" ";
			else
				cout<<-1<<" ";
		}
		cout<<endl;
	}
}