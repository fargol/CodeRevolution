#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,n,sum;
	cin>>T;
	while(T--){
		cin>>n;
		int arr[n];
		for(int &i:arr)
			cin>>i;
		cin>>sum;
		int dp[sum+1][n+1];
		int count=0;
		for(int i=0;i<n+1;i++)
			dp[0][i]=1;
		for(int i=1;i<=sum;i++)
			dp[i][0]=0;
		for(int i=1;i<=sum;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=dp[i][j-1];
				if(arr[j-1]<=i){
					dp[i][j]+=dp[i-arr[j-1]][j-1];
				}
			}
		}
		cout<<dp[sum][n]<<endl;
	}
}