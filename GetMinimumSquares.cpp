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
	while(T--){
		cin>>N;
		int dp[N+1];
		dp[0]=0;
		dp[1]=1;
		for(int i=2;i<=N;i++){
			int min_squares=INT_MAX;
			for(int j=1;j*j<=i;j++){
				min_squares=min(min_squares,dp[i-j*j]+1);
			}
			dp[i]=min_squares;
		}
		cout<<dp[N]<<endl;
	}
}