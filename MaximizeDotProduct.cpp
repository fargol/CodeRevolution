#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
bool cmp(const int A,const int B){
	return A>B?true:false;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,M;
	long long int dp[1010][1010];
	long long int prod;
	long long int A[1010],B[1010];
	cin>>T;
	while(T--){
		cin>>N>>M;
		for(int i=0;i<N;i++){
			cin>>A[i];
		}
		for(int i=0;i<M;i++)
			cin>>B[i];
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++)
				dp[i][j]=0;
		}
		for(int i=1;i<=M;i++){
			for(int j=i;j<=N;j++){
				dp[i][j]=max((dp[i-1][j-1]+(B[i-1]*A[j-1])),dp[i][j-1]);
			}
		}
		cout<<dp[M][N]<<endl;
	}
}