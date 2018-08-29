#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,n,m,x,y;
	cin>>T;
	int graph[25][25];
	while(T--){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				cin>>graph[i][j];
		}
		cin>>x>>y;
		queue<pair<int,int> > Q;
		bool visited[n][m];
		int dist[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				visited[i][j]=false;
				dist[i][j]=-1;
			}
		}
		if(graph[0][0]==1){
			Q.push(make_pair(0,0));
			dist[0][0]=0;
		}
		//cout<<"dist = "<<dist[2][5]<<endl;
		while(!Q.empty()){
			pair<int,int> t=Q.front();
			visited[t.first][t.second]=true;
			//cout<<"Coord = "<<t.first<<" "<<t.second<<endl;
			if(t.first==x&&t.second==y)
				break;
			Q.pop();
			if(t.first>0){
				//dist[t.first-1][t.second]=-1;
				if(graph[t.first-1][t.second]==1&&!visited[t.first-1][t.second]){
					dist[t.first-1][t.second]=dist[t.first][t.second]+1;
					Q.push(make_pair(t.first-1,t.second));
				}
			}
			if(t.second>0){
				//dist[t.first][t.second-1]=-1;
				if(graph[t.first][t.second-1]==1&&!visited[t.first][t.second-1]){
					dist[t.first][t.second-1]=dist[t.first][t.second]+1;
					Q.push(make_pair(t.first,t.second-1));
				}
			}
			if(t.first<n-1){
				//dist[t.first+1][t.second]=-1;
				if(graph[t.first+1][t.second]==1&&!visited[t.first+1][t.second]){
					dist[t.first+1][t.second]=dist[t.first][t.second]+1;
					Q.push(make_pair(t.first+1,t.second));
				}
			}
			if(t.second<m-1){
				//dist[t.first][t.second+1]=-1;
				if(graph[t.first][t.second+1]==1&&!visited[t.first][t.second+1]){
					dist[t.first][t.second+1]=dist[t.first][t.second]+1;
					Q.push(make_pair(t.first,t.second+1));
				}
			}
		}
		cout<<dist[x][y]<<endl;
	}	
}