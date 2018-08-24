#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,n,dp[100][100];
	string S;
	cin>>T;
	while(T--){
		cin>>S;
		n=S.length();
		memset(dp,0,sizeof(dp));
		for(int gap=1;gap<n;gap++){
			for(int l=0,h=gap;h<n;l++,h++){
				if(S[l]==S[h])
					dp[l][h]=dp[l+1][h-1];
				else
					dp[l][h]=min(dp[l][h-1],dp[l+1][h])+1;
			}
		}
		cout<<dp[0][n-1]<<endl;
	}	
}