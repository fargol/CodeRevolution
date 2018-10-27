#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
#define ll long long
int main(){
	ios::sync_with_stdio(true);
	int T,N,A[1000001];
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>A[i];
		int dp[N],LIS=1;
		dp[0]=1;
		for(int i=1;i<N;i++){
			dp[i]=1;
			for(int j=0;j<i;j++){
				if(A[j]<A[i]&&(i-j)<=(A[i]-A[j])){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
			LIS=max(LIS,dp[i]);
		}
		cout<<(N-LIS)<<endl;
	}
}