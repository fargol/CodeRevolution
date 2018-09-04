#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,K,A[1100],count;
	cin>>T;
	while(T--){
		cin>>N>>K;
		for(int i=0;i<N;i++)
			cin>>A[i];
		sort(A,A+N);
		count=0;
		for(int i=0;i<N;i++){
			if(K>=A[i]){
				count++;
				K-=A[i];
			}
		}
		cout<<count<<endl;
	}	
}