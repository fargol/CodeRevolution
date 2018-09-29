#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,m,n;
	cin>>T;
	while(T--){
		cin>>m>>n;
		int C[m][n];
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>C[i][j];
			}
		}
		int S[m][n];
		int maxS=INT_MIN;
		for(int i=0;i<m;i++)
			S[i][0]=C[i][0];
		for(int j=0;j<n;j++)
			S[0][j]=C[0][j];
		for(int i=1;i<m;i++){
			for(int j=1;j<n;j++){
				if(C[i][j]==1){
					S[i][j]=min(S[i][j-1],min(S[i-1][j],S[i-1][j-1]))+1;
				}
				else{
					S[i][j]=0;
				}
			}
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				maxS=max(maxS,S[i][j]);
			}
		}
		cout<<maxS<<endl;
	}
}