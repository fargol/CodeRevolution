#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	int C[1000];
	int dp[1000];
	int maxDp;
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>C[i];
		dp[0]=C[0];
		maxDp=dp[0];
		for(int i=1;i<N;i++){
			dp[i]=C[i];
			for(int j=0;j<i-1;j++){
				if(dp[i]<dp[j]+C[i])
					dp[i]=dp[j]+C[i];
			}
			if(maxDp<dp[i])
				maxDp=dp[i];
		}
		cout<<maxDp<<endl;
	}		
}