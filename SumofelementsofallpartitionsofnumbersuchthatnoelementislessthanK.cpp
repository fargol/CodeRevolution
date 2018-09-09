#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int func(int N,int K,vector<vector<int> >dp){
	if(N<K)
		return 0;
	if(N<K<<1)
		return 1;

	if(dp[N][K]>=0)
		return dp[N][K];
	dp[N][K]=1;
	for(int i=K;i<N;i++){
		dp[N][K]+=func(N-i,i,dp);
	}
	return dp[N][K];
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int N,K;
	cin>>N>>K;
	vector<vector<int> > dp(N+1,vector<int>(K+1,-1));
	cout<<func(N,K,dp)*N<<endl;
}