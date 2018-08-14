#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
#define M 1000000007;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,n,m;
	cin>>T;
	long long int dp[110][110];
	for(int i=1;i<110;i++){
		dp[i][1]=1;
		dp[1][i]=1;
	}
	for(int i=2;i<110;i++){
		for(int j=2;j<110;j++){
			dp[i][j]=dp[i-1][j]+dp[i][j-1];//+dp[i-1][j-1]%M;
			dp[i][j]%=M;
		}
	}
	while(T--){
		cin>>n>>m;
		cout<<dp[n][m]<<endl;
	}	
}