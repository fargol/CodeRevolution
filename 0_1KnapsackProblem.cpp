#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T;
	cin>>T;
	while(T--){
		int N; //No. of items;
		int W; //capacity of knapsack
		cin>>N;
		cin>>W;
		vector<int> val(N);
		vector<int> wt(N);
		for(int &i:val)
			cin>>i;
		for(int &i:wt)
			cin>>i;
		vector<vector<int> > dp(N,vector<int>(W+1));
		for(int i=0;i<N;i++)
			dp[i][0]=0;
		for(int j=0;j<=W;j++){
			if(wt[0]<=j)
				dp[0][j]=val[0];
			else
				dp[0][j]=0;
		}
		for(int i=1;i<N;i++){
			for(int j=0;j<=W;j++){
				if(wt[i]<=j){
					dp[i][j]=max(val[i]+dp[i-1][j-wt[i]],dp[i-1][j]);
				}
				else
					dp[i][j]=dp[i-1][j];
			}
		}
		cout<<dp[N-1][W]<<endl;
	}
}