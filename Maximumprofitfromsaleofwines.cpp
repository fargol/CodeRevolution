#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int N;
int maxProfit(int price[],int dp[][100],int beg,int end){
	if(beg>end)
		return 0;
	if(dp[beg][end]!=-1)
		return dp[beg][end];
	int year=N-(end-beg+1)+1;
	return dp[beg][end]=max(maxProfit(price,dp,beg+1,end)+year*price[beg],
		maxProfit(price,dp,beg,end-1)+year*price[end]);
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int price[100];
	cin>>N;
	int dp[100][100];
	for(int i=0;i<N;i++){
		cin>>price[i];
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			dp[i][j]=-1;
	cout<<(maxProfit(price,dp,0,N-1))<<endl;
}