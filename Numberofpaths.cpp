#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,n,m;
	cin>>T;
	while(T--){
		cin>>n>>m;
		int dp[n+1][m+1];
		dp[0][0]=0;
		for(int i=0;i<=n;i++)
			dp[i][1]=1;
		for(int j=0;j<=m;j++)
			dp[1][j]=1;
		for(int i=2;i<=n;i++){
			for(int j=2;j<=m;j++){
				dp[i][j]=dp[i-1][j]+dp[i][j-1];//+dp[i-1][j-1];
			}
		}
		cout<<dp[n][m]<<endl;
	}
}