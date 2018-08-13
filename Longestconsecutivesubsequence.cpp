#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	int arr[1000];
	int dp[1000],dpMax[1000],dpMin[1000];
	int maxl;
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>arr[i];
		}
		dp[0]=1;
		dpMax[0]=dpMin[0]=arr[0];
		maxl=dp[0];
		for(int i=1;i<N;i++){
			dp[i]=1;
			dpMax[i]=dpMin[i]=arr[i];
			for(int j=0;j<i;j++){
				if(abs(dpMax[j]-arr[i])==1||abs(dpMin[j]-arr[i])==1){
					if(dp[i]<dp[j]+1){
						dp[i]=dp[j]+1;
						if(arr[i]<dpMin[j])
							dpMin[i]=arr[i];
						else
							dpMin[i]=dpMin[j];
						if(arr[i]>dpMax[j])
							dpMax[i]=arr[i];
						else
							dpMax[i]=dpMax[j];
					}
				}
			}
			if(maxl<dp[i])
				maxl=dp[i];
		}
		cout<<maxl<<endl;
	}		
}