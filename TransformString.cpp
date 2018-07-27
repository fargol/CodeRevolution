#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T;
	string A,B;
	cin>>T;
	int** dp;
	dp=(int**)calloc(100010,sizeof(int*));
	for(int i=0;i<100010;i++)
		dp[i]=(int*)calloc(100010,sizeof(int));
	//vector<vector<int> > dp(100010,vector<int>(100010));
	while(T--){
		cin>>A>>B;
		for(int i=0;i<=A.length();i++)
			dp[i][0]=i;
		for(int j=0;j<=B.length();j++)
			dp[0][j]=j;
		for(int i=1;i<=A.length();i++){
			for(int j=1;j<=B.length();j++){
				if(A[i-1]==B[j-1])
					dp[i][j]=dp[i-1][j-1];
				else
					dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
			}
		}
		cout<<(dp[A.length()][B.length()]/2)<<endl;
	}
}