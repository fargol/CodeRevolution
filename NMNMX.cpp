#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
#define M 1000000007;
inline long long int modular_exp(long long int num,long long int exp){
	long long int res=1;
	num%=M;
	while(exp>0){
		if(exp&1){
			res=(res*num)%M;
			res%M;
		}
		exp=exp>>1;
		num=(num*num)%M;
		num%=M;
	}
	res%=M;
	return res;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,K;
	cin>>T;
	vector<long long int> arr(5010);
	vector<vector<long long int> > dp(5010,vector<long long int>(5010));
	vector<long long int> factor(5010);
	long long int ans;
	for(int i=1;i<5010;i++)
		dp[i][0]=1;
	dp[1][1]=1;
	for(int i=2;i<5010;i++){
		for(int j=1;j<5010;j++){
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
		}
	}
	while(T--){
		cin>>N>>K;
		ans=1;
		for(int i=1;i<=N;i++){
			cin>>arr[i];
			factor[i]=dp[N-1][K-1]-dp[i-1][K-1];
			factor[i]-=dp[N-i][K-1];
		}
		for(int i=1;i<=N;i++){
			ans*=modular_exp(arr[i],factor[i]);
			ans%=M;
		}
		ans%=M;
		cout<<ans<<endl;
	}
}