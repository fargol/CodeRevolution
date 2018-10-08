#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
int main(){
	ios::sync_with_stdio(true);
	int T,n,r;
	cin>>T;
	while(T--){
		cin>>n>>r;
		if(r>n){
			cout<<0<<endl;
			continue;
		}
		int dp[n+1][r+1];
		for(int i=0;i<=n;i++)
			dp[i][0]=1;
		for(int j=1;j<=r;j++)
			dp[0][j]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=min(n,r);j++){
				dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%M;
			}
		}
		cout<<dp[n][r]<<endl;
	}
}