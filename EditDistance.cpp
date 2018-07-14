#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,P,Q;
	string S1,S2;
	cin>>T;
	while(T--){
		cin>>P>>Q;
		cin>>S1>>S2;
		vector<vector<int> > dp(P+1,vector<int>(Q+1));
		for(int i=0;i<=P;i++)
			dp[i][0]=i;
		for(int i=0;i<=Q;i++)
			dp[0][i]=i;
		for(int i=1;i<=P;i++){
			for(int j=1;j<=Q;j++){
				if(S1[i-1]==S2[j-1])
					dp[i][j]=dp[i-1][j-1];
				else
					dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
			}
		}
		cout<<dp[P][Q]<<endl;
	}	
}