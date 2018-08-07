#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	int dp[100];
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	dp[3]=3;
	while(T--){
		cin>>N;
		for(int i=3;i<=N;i++){
			dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
		}
		cout<<dp[N]<<endl;
	}
}