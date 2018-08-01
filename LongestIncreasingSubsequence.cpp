#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	int arr[1010];
	int dp[1010];
	cin>>T;
	int maxDp;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>arr[i];
		dp[0]=1;
		maxDp=1;
		for(int i=1;i<N;i++){
			dp[i]=1;
			for(int j=0;j<i;j++){
				if(arr[j]<arr[i]){
					if(dp[i]<dp[j]+1)
						dp[i]=dp[j]+1;
				}
			}
			if(maxDp<dp[i])
				maxDp=dp[i];
		}
		cout<<maxDp<<endl;
	}
}