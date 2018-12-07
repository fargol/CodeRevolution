#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
#define ll long long
int main(){
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
			cin>>arr[i];
		int dp[N];
		dp[N-1]=arr[N-1];
		if(N>=2)
			dp[N-2]=max(dp[N-1],arr[N-2]);
		for(int i=N-3;i>=0;i--){
			dp[i]=max(dp[i+2]+arr[i],dp[i+1]);
		}
		cout<<dp[0]<<endl;
	}
}