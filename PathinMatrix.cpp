#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,max;
	int arr[100][100];
	int dp[100][100];
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cin>>arr[i][j];
			}
		}
		for(int i=0;i<N;i++)
			dp[0][i]=arr[0][i];
		for(int i=1;i<N;i++){
			max=INT_MIN;
			for(int j=0;j<N;j++){
				dp[i][j]=dp[i-1][j];
				if(j>0){
					if(dp[i][j]<dp[i-1][j-1])
						dp[i][j]=dp[i-1][j-1];
				}
				if(j<N-1){
					if(dp[i][j]<dp[i-1][j+1])
						dp[i][j]=dp[i-1][j+1];
				}
				dp[i][j]+=arr[i][j];
				if(max<dp[i][j])
					max=dp[i][j];
			}
		}
		cout<<max<<endl;
	}
}