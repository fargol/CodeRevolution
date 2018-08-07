#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	int arr[1000];
	long long int sum,sum1;
	int dp[100][10000];
	while(T--){
		cin>>N;
		sum1=0;
		for(int i=0;i<N;i++){
			cin>>arr[i];
			sum1+=arr[i];
		}
		sum=sum1>>1;
		for(int i=0;i<N;i++){
			dp[i][0]=0;
		}
		for(int j=0;j<=sum;j++){
			if(arr[0]<=j)
				dp[0][j]=arr[0];
			else
				dp[0][j]=0;
		}
		for(int i=1;i<N;i++){
			for(int j=1;j<=sum;j++){
				if(arr[i]<=j){
					dp[i][j]=max(arr[i]+dp[i-1][j-arr[i]],dp[i-1][j]);
				}
				else{
					dp[i][j]=dp[i-1][j];
				}
			}
		}
		if(sum1&1){
			cout<<2*abs(sum-dp[N-1][sum])+1<<endl;
		}
		else{
			cout<<2*abs(sum-dp[N-1][sum])<<endl;
		}
	}
}