
// A C / C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the grap
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int g[MAX][MAX];
void dijkstra(int graph[MAX][MAX], int ,int V);
int main()
{
   /* Let us create the example graph discussed above */
   int t;
int V;
   cin>>t;
   while(t--){
cin>>V;
  for(int i=0;i<V;i++)
  {
  	for(int j=0;j<V;j++)
  	{
  		cin>>g[i][j];
  	}
  }
  int s;
  cin>>s;
    dijkstra(g, s,V);
cout<<endl;
   }
    return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The function prints V space separated integers where 
    the ith integer denote the shortest distance of ith vertex
    from source vertex */
void dijkstra(int graph[MAX][MAX], int s,int V)
{
   //Your code here
   long long int dist[V];
   for(int i=0;i<V;i++)
    dist[i]=INT_MAX;
  dist[s]=0;
  long long int min_id,min_dist;
  bool tree[V]={false};
  for(int i=0;i<V;i++){
    min_dist=INT_MAX;
    for(int i=0;i<V;i++){
      if(!tree[i]&&min_dist>dist[i]){
        min_dist=dist[i];
        min_id=i;
      }
    }
    tree[min_id]=true;
    //cout<<"min_id = "<<min_id<<endl;
    for(int i=0;i<V;i++){
      if(dist[i]>dist[min_id]+graph[min_id][i])
        dist[i]=dist[min_id]+graph[min_id][i];
    }
  }
  for(int i=0;i<V;i++)
    cout<<dist[i]<<" ";
}