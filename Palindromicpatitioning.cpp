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
	string S;
	cin>>T;
	while(T--){
		cin>>S;
		int N=S.length();
		bool P[N][N];
		for(int i=0;i<N;i++)
			P[i][i]=true;
		for(int l=2;l<=N;l++){
			for(int i=0;i<=N-l;i++){
				int j=i+l-1;
				if(l==2)
					P[i][j]=(S[i]==S[j]);
				else
					P[i][j]=(S[i]==S[j])&&P[i+1][j-1];
			}
		}
		int C[N];
		C[0]=0;
		for(int i=1;i<N;i++){
			if(P[0][i])
				C[i]=0;
			else{
				C[i]=INT_MAX;
				for(int j=0;j<i;j++){
					if(P[j+1][i])
						C[i]=min(1+C[j],C[i]);
				}
			}
		}
		cout<<C[N-1]<<endl;
	}
}