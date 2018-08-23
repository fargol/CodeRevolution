#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,A,B,maxS;
	cin>>T;
	string X,Y;
	while(T--){
		cin>>A>>B;
		cin>>X>>Y;
		int dp[A+1][B+1];
		dp[0][0]=0;
		for(int i=1;i<=A;i++)
			dp[i][0]=0;
		for(int i=1;i<=B;i++)
			dp[0][i]=0;
		maxS=0;
		for(int i=1;i<=A;i++){
			for(int j=1;j<=B;j++){
				if(X[i-1]==Y[j-1]){
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else
					dp[i][j]=0;
				maxS=max(maxS,dp[i][j]);
			}
		}
		cout<<maxS<<endl;
	}	
}