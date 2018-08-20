#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,maxllap;
	int arr[4999];
	vector<vector<int> > dp(4999,vector<int>(4999));
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>arr[i];
		for(int i=0;i<N-1;i++){
			dp[i][N-1]=2;
			dp[i][i]=1;
		}
		if(N<2)
		    maxllap=1;
		else
		    maxllap=2;
		for(int j=N-2;j>=1;j--){
			int i=j-1,k=j+1;
			while(i>=0&&k<N){
				if(arr[i]+arr[k]==2*arr[j]){
					dp[i][j]=dp[j][k]+1;
					maxllap=max(maxllap,dp[i][j]);
					i--;
					k++;
				}
				else if(arr[i]+arr[k]<2*arr[j]){
					k++;
				}
				else{
				    dp[i][j]=2;
					i--;
				}
			}
			while (i >= 0)
            {
                dp[i][j] = 2;
                i--;
            }
		}
		cout<<maxllap<<endl;
	}	
}