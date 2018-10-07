#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
//#define M 1000000007;
bool Hamiltonian(vector<vector<int> > &graph,
	int v,bool visited[],int N,int count){

	if(visited[v]&&count==N)
		return true;
	if(visited[v]&&count<N)
		return false;
	visited[v]=true;
	for(int i=0;i<graph[v].size();i++){
		if(Hamiltonian(graph,graph[v][i],visited,N,count+1))
			return true;
	}
	visited[v]=false;
	return false;
}
bool check(vector<vector<int> > &graph,int N){
	bool visited[N+1]={false};
	int count=0;
	for(int i=1;i<=N;i++){
		if(Hamiltonian(graph,i,visited,N,count))
			return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(true);
	int T,N,M,x,y;
	cin>>T;
	while(T--){
		cin>>N>>M;
		vector<vector<int> > graph(N+1);
		for(int i=0;i<M;i++){
			cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		if(check(graph,N)){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
}