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
	string S1,S2;
	while(T--){
		cin>>m>>n;
		cin>>S1>>S2;
		vector<int> positions[26];
		for(int i=1;i<=n;i++){
			positions[S2[i-1]-'a'].push_back(i);
		}
		int LCSL[m+2][n+2],LCSR[m+2][n+2];
		for(int i=0;i<m+2;i++){
			for(int j=0;j<n+2;j++)
				LCSL[i][j]=LCSR[i][j]=0;
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(S1[i-1]==S2[j-1]){
					LCSL[i][j]=LCSL[i-1][j-1]+1;
				}
				else{
					LCSL[i][j]=max(LCSL[i-1][j],LCSL[i][j-1]);
				}
			}
		}
		for(int i=m;i>=1;i--){
			for(int j=n;j>=1;j--){
				if(S1[i-1]==S2[j-1]){
					LCSR[i][j]=LCSR[i+1][j+1]+1;
				}
				else{
					LCSR[i][j]=max(LCSR[i+1][j],LCSR[i][j+1]);
				}
			}
		}
		int ways=0;
		for(int i=0;i<=m;i++){
			for(char c='a';c<='z';c++){
				for(int j=0;j<positions[c-'a'].size();j++){
					int p=positions[c-'a'][j];
					if(LCSL[i][p-1]+LCSR[i+1][p+1]==LCSL[m][n])
						ways++;
				}	
			}
		}
		cout<<ways<<endl;
	}
}