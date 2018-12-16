#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define M 1000000007
int main(){
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		vector<ll int> dp(N+1);
		dp[0]=0;
		dp[1]=1;
		dp[2]=2;
		for(int i=3;i<=N;i++){
			dp[i]=dp[i-1]+dp[i-2];
			dp[i]%=M;
		}
		cout<<dp[N]<<endl;
	}
}