#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int _size,N;
        cin>>_size>>N;
        Graph *g = new Graph(_size);
        for(int i=0;i<N;i++)
        {
            int u,v;
            cin>>u>>v;
            g->addEdge(u,v);
        }
        cout<<g->isCyclic()<<endl;
    }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure of the class is as follows 
which contains an integer V denoting the no 
of vertices and a list of adjacency vertices.
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};
*/
/*You are required to complete this method*/
bool dfs_cycle(bool *visited,bool *recStack,int node,int V,list<int> *adj){
    if(!visited[node]){
        visited[node]=true;
        recStack[node]=true;
        for(auto i=adj[node].begin();i!=adj[node].end();i++){
            if(!visited[*i]&&dfs_cycle(visited,recStack,*i,V,adj))
                return true;
            else if(recStack[*i])
                return true;
        }
    }
    recStack[node]=false;
    return false;
}
bool Graph :: isCyclic()
{
//Your code here
    bool visited[V]={false};
    bool recStack[V]={false};
    for(int i=0;i<V;i++){
        if(dfs_cycle(visited,recStack,i,V,adj))
            return true;
    }
    return false;
}