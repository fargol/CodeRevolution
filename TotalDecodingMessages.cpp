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
	string S;
	cin>>T;
	while(T--){
		cin>>N>>S;
		int dp[N+1];
		dp[0]=1;
		if(S[0]!='0'){
			dp[1]=1;
		}
		else{
			dp[1]=0;
		}
		for(int i=2;i<=N;i++){
			if(S[i-1]!='0'){
				dp[i]=dp[i-1];
			}
			else{
				dp[i]=0;
			}
			if(S.substr(i-2,2)>="1"&&S.substr(i-2,2)<="26")
				dp[i]+=dp[i-2];
		}
		cout<<dp[N]<<endl;
	}		
}