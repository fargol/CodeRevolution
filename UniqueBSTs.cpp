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
	int dp[15];
	dp[0]=dp[1]=1;
	for(int i=2;i<15;i++){
		dp[i]=0;
		for(int j=0;j<i;j++)
			dp[i]+=dp[j]*dp[i-j-1];
	}
	while(T--){
		cin>>N;
		cout<<dp[N]<<endl;
	}
}