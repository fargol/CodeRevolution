#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	long long int sum;
	cin>>T;
	vector<int> arr(110);
	while(T--){
		cin>>N;
		sum=0;
		for(int i=0;i<N;i++){
			cin>>arr[i];
			sum+=arr[i];
		}
		if(sum&1)
			cout<<"NO\n";
		else{
			sum>>=1;
			//cout<<sum<<endl;
			vector<vector<bool> > dp(sum+1,vector<bool>(N+1));
			for(int j=0;j<=N;j++)
				dp[0][j]=true;
			for(int i=1;i<=sum;i++)
				dp[i][0]=false;
			for(int i=1;i<=sum;i++){
				for(int j=1;j<=N;j++){
					dp[i][j]=dp[i][j-1];
					if(i>=arr[j-1])
						dp[i][j]=(dp[i-arr[j-1]][j-1]||dp[i][j]);
				}
			}
			if(dp[sum][N])
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
}