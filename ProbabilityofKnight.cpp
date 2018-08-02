#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
inline bool inside_board(int x,int y,int N){
	if(x>=0&&y>=0&&x<=N-1&&y<=N-1)
		return true;
	else
		return false;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,X,Y,K;
	cin>>T;
	int dx[8]={1,2,1,2,-1,-1,-2,-2};
	int dy[8]={2,1,-2,-1,2,-2,1,-1};
	int nx,ny;
	while(T--){
		cin>>N>>X>>Y>>K;
		double dp[N][N][K+1];
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)
				dp[i][j][0]=1;
		}
		for(int k=1;k<=K;k++){
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					dp[i][j][k]=0.0;
					for(int d=0;d<8;d++){
						nx=i+dx[d];
						ny=j+dy[d];
						if(inside_board(nx,ny,N))
							dp[i][j][k]+=dp[nx][ny][k-1]/8.0;
					}
				}
			}
		}
		printf("%.6lf\n",dp[X][Y][K]);
	}
}