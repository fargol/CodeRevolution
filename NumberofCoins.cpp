#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,V,C[15000],dp[15000],minC;
	cin>>T;
	while(T--){
		cin>>V>>N;
		minC=INT_MAX;
		for(int i=0;i<N;i++){
			cin>>C[i];
			minC=min(minC,C[i]);
		}
		dp[0]=0;
		for(int i=1;i<minC;i++){
		    dp[i]=-1;
		}
		for(int i=minC;i<=V;i++){
			dp[i]=INT_MAX;
			for(int j=0;j<N;j++){
				if(i>=C[j]){
					if(dp[i-C[j]]>-1&&dp[i]>dp[i-C[j]]+1)
						dp[i]=dp[i-C[j]]+1;
				}
			}
			if(dp[i]>=INT_MAX)
			    dp[i]=-1;
		}
		cout<<dp[V]<<endl;
	}		
}