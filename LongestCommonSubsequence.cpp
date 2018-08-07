#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,A,B;
	cin>>T;
	string S1,S2;
	int dp[110][110];
	for(int i=0;i<110;i++){
		dp[i][0]=dp[0][i]=0;
	}
	while(T--){
		cin>>A>>B;
		cin>>S1>>S2;
		for(int i=1;i<=A;i++){
			for(int j=1;j<=B;j++){
				if(S1[i-1]==S2[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		cout<<dp[A][B]<<endl;
	}
}