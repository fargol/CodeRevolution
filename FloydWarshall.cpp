#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,V;
	cin>>T;
	while(T--){
		cin>>V;
		int graph[V][V];
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++)
				cin>>graph[i][j];
		}
		for(int k=0;k<V;k++){
			for(int i=0;i<V;i++){
				for(int j=0;j<V;j++){
					if(graph[i][j]>graph[i][k]+graph[k][j])
						graph[i][j]=graph[i][k]+graph[k][j];
				}
			}
		}
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				cout<<graph[i][j]<<" ";
			}
			cout<<endl;
		}
	}		
}