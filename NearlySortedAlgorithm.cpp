#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
int main(){
	ios::sync_with_stdio(true);
	int T,N,K;
	cin>>T;
	while(T--){
		cin>>N>>K;
		int arr[N];
		for(int &i:arr)
			cin>>i;
		priority_queue<int,vector<int>,greater<int> > min_heap;
		for(int i=0;i<=min(K,N-1);i++)
			min_heap.push(arr[i]);
		int j=K+1;
		for(int i=0;i<N;i++){
			cout<<min_heap.top()<<" ";
			min_heap.pop();
			if(j<N){
				min_heap.push(arr[j]);
				j++;
			}
		}
		cout<<endl;
	}
}