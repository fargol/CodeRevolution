#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<vector<int> > graph(n+1);
    for(int a0 = 0; a0 < m; a0++){
        int x;
        int y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<bool> visited(n+1,false);
    vector<pair<long long int,long long int> > edgeCount;
    queue<int> Q;
    long long int edge,happy=0,vertex;
    int f=2;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            Q.push(i);
        edge=0;
        vertex=0;
        while(!Q.empty()){
            int node=Q.front();
            //cout<<"node = "<<node<<endl;
            Q.pop();
            if(!visited[node]){
            for(int j=0;j<graph[node].size();j++){
                if(!visited[graph[node][j]]){
                    Q.push(graph[node][j]);
                    edge++;
                }
            }
            visited[node]=true;
            vertex++;}
        }
        if(edge>vertex)
            f-=2;
        else if(edge==vertex)
            f--;
        happy+=(vertex)*(vertex-1);
        //cout<<" I : "<<i<<" "<<edge<<" "<<vertex<<" ::happy = "<<happy<<endl;
        edgeCount.push_back(make_pair(edge,vertex));}
    }
    int j=-1;
    /*for(int i=0;i<edgeCount.size();i++){
        cout<<" f = "<<edgeCount[i].first<<" s = "<<edgeCount[i].second<<endl;
    }*/
    while(f>0){
        //cout<<f<<endl;
        long long int min=LLONG_MAX;
        //cout<<"h min = "<<min<<endl;
        for(int i=0;i<edgeCount.size()&&i!=j;i++){
            if(min>edgeCount[i].second&&edgeCount[i].second>edgeCount[i].first&&edgeCount[i].second!=1){
                min=edgeCount[i].second;
                j=i;
            }
        }
        //cout<<"min = "<<min<<endl;
        happy-=2*(min-1);
        f--;
    }
    cout<<happy<<endl;
    return 0;
}