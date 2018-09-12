#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<long long int, long long int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<long long int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	long long int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		long long int dp[N+1][10];
		for(long long int i=0;i<10;i++){
			dp[0][i]=0;
			dp[1][i]=1;
		}
		for(long long int i=2;i<=N;i++){
			dp[i][0]=dp[i-1][8]+dp[i-1][0];
			dp[i][1]=dp[i-1][1]+dp[i-1][2]+dp[i-1][4];
			dp[i][2]=dp[i-1][2]+dp[i-1][1]+dp[i-1][3]+dp[i-1][5];
			dp[i][3]=dp[i-1][3]+dp[i-1][2]+dp[i-1][6];
			dp[i][4]=dp[i-1][1]+dp[i-1][7]+dp[i-1][5]+dp[i-1][4];
			dp[i][5]=dp[i-1][2]+dp[i-1][4]+dp[i-1][5]+dp[i-1][8]+dp[i-1][6];
			dp[i][6]=dp[i-1][6]+dp[i-1][3]+dp[i-1][9]+dp[i-1][5];
			dp[i][7]=dp[i-1][7]+dp[i-1][4]+dp[i-1][8];
			dp[i][8]=dp[i-1][7]+dp[i-1][5]+dp[i-1][9]+dp[i-1][0]+dp[i-1][8];
			dp[i][9]=dp[i-1][9]+dp[i-1][8]+dp[i-1][6];
		}
		long long int res=0;
		for(long long int i=0;i<10;i++)
			res+=dp[N][i];
		cout<<res<<endl;
	}
}