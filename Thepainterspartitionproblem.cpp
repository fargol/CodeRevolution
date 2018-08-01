#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,n,k,best;
	cin>>T;
	int dp[100][100];
	int A[100];
	int sum[100];
	while(T--){
		cin>>k>>n;
		cin>>A[0];
		sum[0]=A[0];
		for(int i=1;i<n;i++){
			cin>>A[i];
			sum[i]=sum[i-1]+A[i];
		}	
		for(int i=1;i<=k;i++){
			dp[i][1]=A[0];
		}
		for(int i=1;i<=n;i++){
			dp[1][i]=sum[i-1];
		}
		for(int i=2;i<=k;i++){
			for(int j=2;j<=n;j++){
				best=INT_MAX;
				for(int p=1;p<=j;p++)
					best=min(best,max(dp[i-1][p],sum[j-1]-sum[p-1]));
				dp[i][j]=best;
			}
		}
		cout<<dp[k][n]<<endl;
	}
}