#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
//#define M 1000000007;
bool isSafe(int v,vector<vector<int> > &graph,int color[],int c){
	for(int i=0;i<graph[v].size();i++){
		if(color[graph[v][i]]==c)
			return false;
	}
	return true;
}
bool graph_M_Color(vector<vector<int> > &graph,
	int N,int M,int v,int color[]){
	if(v==N+1)
		return true;
	for(int c=1;c<=M;c++){
		if(isSafe(v,graph,color,c)){
			color[v]=c;
			if(graph_M_Color(graph,N,M,v+1,color))
				return true;
			color[v]=0;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(true);
	int T,N,M,E,x,y;
	cin>>T;
	while(T--){
		cin>>N>>M>>E;
		vector<vector<int> > graph(N+1);
		for(int i=0;i<E;i++){
			cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		int color[N+1];
		for(int i=1;i<=N;i++)
			color[i]=0;
		if(graph_M_Color(graph,N,M,1,color)){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
}