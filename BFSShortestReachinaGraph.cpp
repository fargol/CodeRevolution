#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:

        vector<vector<int> > graph;
        
        Graph(int n) {
            graph.resize(n);
        }
    
        void add_edge(int u, int v) {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            queue<int> Q;
            vector<int> dist(graph.size(),0);
            Q.push(start);
            int u;
            while(!Q.empty()){
                u=Q.front();
                Q.pop();
                for(int i=0;i<graph[u].size();i++){
                    if(dist[graph[u][i]]==0){
                        Q.push(graph[u][i]);
                        dist[graph[u][i]]=dist[u]+6;
                    }      
                }
            }
            return dist;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                if(distances[i]==0)
                    distances[i]=-1;
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}