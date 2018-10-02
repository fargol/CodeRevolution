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
	long long int dp[16];
	dp[1]=1;
	for(int i=2;i<=15;i++){
		dp[i]=2*(2*i-1);
		dp[i]*=dp[i-1];
		dp[i]/=(i+1);
	}
	while(T--){
		cin>>N;
		cout<<dp[N>>1]<<endl;
	}
}