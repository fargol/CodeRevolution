#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		int arr[N];
		for(int &i:arr)
			cin>>i;
		int dp[N][N];
		for(int size=0;size<=1;size++){
			int j;
			for(int i=0;i+size<N;i++){
				j=i+size;
				dp[i][j]=0;
			}
		}
		for(int i=0;i+2<N;i++){
			dp[i][i+2]=arr[i]*arr[i+1]*arr[i+2];
		}
		for(int size=3;size<N;size++){
			int j;
			for(int i=0;i+size<N;i++){
				j=i+size;
				dp[i][j]=INT_MAX;
				for(int k=i+1;k<j;k++){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j]);
				}
			}
		} 
		cout<<dp[0][N-1]<<endl;                       
	}
}