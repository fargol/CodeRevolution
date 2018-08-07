#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
inline bool valid(int N,int x,int y,int z){
	if(N==0||N==x||N==y||N==z)
		return true;
	return false;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,x,y,z,max;
	cin>>T;
	int dp[5000];
	while(T--){
		cin>>N>>x>>y>>z;
		dp[0]=0;
		for(int i=1;i<=N;i++){
			dp[i]=0;
			if(i>=x&&(dp[i-x]>0||i==x)){
				if(dp[i]<dp[i-x]+1)
					dp[i]=dp[i-x]+1;
				//cout<<"1:"<<dp[i]<<endl;
			}
			if(i>=y&&(dp[i-y]>0||i==y)){
				if(dp[i]<dp[i-y]+1)
					dp[i]=dp[i-y]+1;
				//cout<<"2:"<<dp[i]<<endl;
			}
			if(i>=z&&(dp[i-z]>0||i==z)){
				if(dp[i]<dp[i-z]+1)
					dp[i]=dp[i-z]+1;
				//cout<<"3:"<<dp[i]<<endl;
			}
			//cout<<" i  = "<<i<<" : "<<dp[i]<<endl;
		}
		cout<<dp[N]<<endl;
	}
}