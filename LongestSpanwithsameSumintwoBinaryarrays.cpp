#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		int A1[N],A2[N];
		for(int &i:A1)
			cin>>i;
		for(int &i:A2)
			cin>>i;
		int diff[2*N+1];
		memset(diff,-1,sizeof(diff));
		int prefix_sum1=0,prefix_sum2=0,curr_diff;
		int maxS=0;
		for(int i=0;i<N;i++){
			prefix_sum1+=A1[i];
			prefix_sum2+=A2[i];
			curr_diff=prefix_sum1-prefix_sum2;
			if(curr_diff==0)
				maxS=max(maxS,i+1);
			else if(diff[N+curr_diff]==-1)
				diff[N+curr_diff]=i;
			else{
				maxS=max(maxS,i-diff[N+curr_diff]);
			}
		}
		cout<<maxS<<endl;
	}
}