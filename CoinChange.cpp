#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,M;
	int A[500];
	cin>>T;
	int dp[500][500];
	while(T--){
		cin>>M;
		for(int i=0;i<M;i++)
			cin>>A[i];
		cin>>N;
		for(int i=0;i<M;i++)
			dp[0][i]=1;
		for(int i=1;i<=N;i++){
			for(int j=0;j<M;j++){
				dp[i][j]=0;
				if(i>=A[j])
					dp[i][j]=dp[i-A[j]][j];
				if(j>=1)
					dp[i][j]+=dp[i][j-1];
			}
		}
		cout<<dp[N][M-1]<<endl;
	}
}