#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,X,Y;
	cin>>T;
	while(T--){
		cin>>N>>X>>Y;
		int A[N],B[N];
		for(int &i:A)
			cin>>i;
		for(int &i:B)
			cin>>i;
		int dp[N+1][X+1][Y+1];
		for(int i=0;i<=N;i++){
			for(int j=0;j<=X;j++){
				for(int k=0;k<=Y;k++)
					dp[i][j][k]=0;
			}
		}
		for(int i=0;i<=N;i++)
			dp[i][0][0]=0;
		for(int i=0;i<=X;i++){
			for(int j=0;j<=Y;j++)
				dp[0][i][j]=0;
		}
		for(int i=1;i<=N;i++){
			for(int j=1;j<=X;j++){
				dp[i][j][0]+=dp[i-1][j-1][0]+A[i-1];
			}
		}
		for(int i=1;i<=N;i++){
			for(int k=1;k<=Y;k++){
				dp[i][0][k]+=dp[i-1][0][k-1]+B[i-1];
			}
		}
		for(int i=1;i<=N;i++){
			for(int j=1;j<=X;j++){
				for(int k=1;k<=Y;k++){
					dp[i][j][k]=max(dp[i-1][j-1][k]+A[i-1],dp[i-1][j][k-1]+B[i-1]);
				}
			}
		}
		cout<<dp[N][X][Y]<<endl;
	}
}