#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int minSteps(vector<int> &arr,vector<int> &dp,int N){
	if(arr[0]==0||N==0)
		return INT_MAX;
	dp[0]=0;
	for(int i=1;i<N;i++){
		dp[i]=INT_MAX;
		for(int j=0;j<i;j++){
			if(i<=j+arr[j]&&dp[j]!=INT_MAX){
				dp[i]=min(dp[i],dp[j]+1);
			}
		}
	}
	return dp[N-1];
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,res;
	cin>>T;
	vector<int> arr(110);
	vector<int> dp(110);
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>arr[i];
		res=minSteps(arr,dp,N);
		if(res==INT_MAX){
			cout<<-1<<endl;
		}
		else{
			cout<<res<<endl;
		}
	}
}	