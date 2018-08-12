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
	int A[1000];
	int dp[1000];
	int maxDp;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>A[i];
		dp[0]=A[0];
		maxDp=dp[0];
		for(int i=1;i<N;i++){
			dp[i]=A[i];
			for(int j=0;j<i;j++){
				if(A[j]<A[i]){
					if(dp[i]<dp[j]+A[i])
						dp[i]=dp[j]+A[i];
				}
			}
			if(maxDp<dp[i])
				maxDp=dp[i];
		}
		cout<<maxDp<<endl;
	}
}