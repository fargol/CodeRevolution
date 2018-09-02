#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
//#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
bool validPos(int x,int y,int N,int M){
	return (x>=1&&x<=N&&y>=1&&y<=M);
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,M,Xk,Yk,Xt,Yt,count;
	cin>>T;
	int dx[]={-2,-2,-1,-1,1,1,2,2};
	int dy[]={-1,1,-2,2,-2,2,-1,1};
	bool flag;
	while(T--){
		cin>>N>>M;
		cin>>Xk>>Yk>>Xt>>Yt;
		bool visited[N+1][M+1];
		int dist[N+1][M+1];
		for(int i=1;i<=N;i++){
			for(int j=1;j<=M;j++){
				visited[i][j]=false;
				dist[i][j]=INT_MAX;
			}
		}
		queue<pair<int,int> > Q;
		Q.push(make_pair(Xk,Yk));
		dist[Xk][Yk]=0;
		count=0;
		flag=false;
		while(!Q.empty()){
			int x=Q.front().first;
			int y=Q.front().second;
			visited[x][y]=true;
			if(x==Xt&&y==Yt){
				break;
			}
			for(int i=0;i<8;i++){
				if(!visited[x+dx[i]][y+dy[i]]&&validPos(x+dx[i],y+dy[i],N,M)){
					Q.push(make_pair(x+dx[i],y+dy[i]));
					dist[x+dx[i]][y+dy[i]]=dist[x][y]+1;
				}
			}
			Q.pop();
		}
		if(dist[Xt][Yt]<INT_MAX){
			cout<<dist[Xt][Yt]<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
}