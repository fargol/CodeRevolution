#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
#define ll long long
int main(){
	ios::sync_with_stdio(true);
	int T,R,C;
	cin>>T;
	while(T--){
		cin>>R>>C;
		vector<vector<int> > matrix(R,vector<int>(C));
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++)
				cin>>matrix[i][j];
		}
		vector<vector<int> > dp(R,vector<int>(C));
		dp[R-1][C-1]=matrix[R-1][C-1]>0?1:(1-matrix[R-1][C-1]);
		for(int i=R-2;i>=0;i--){
			dp[i][C-1]=max(dp[i+1][C-1]-matrix[i][C-1],1);
		}
		for(int j=C-2;j>=0;j--){
			dp[R-1][j]=max(dp[R-1][j+1]-matrix[R-1][j],1);
		}
		for(int i=R-2;i>=0;i--){
			for(int j=C-2;j>=0;j--){
				int min_exit=min(dp[i+1][j],dp[i][j+1]);
				dp[i][j]=max(min_exit-matrix[i][j],1);
			}
		}
		cout<<dp[0][0]<<endl;
	}
}