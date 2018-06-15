#include <bits/stdc++.h>

using namespace std;

// Complete the maxRegion function below.
int dfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &visited,int c){
    visited[i][j]=1;
    c++;
    int n=grid.size();
    int m=grid[0].size();
     if(i>0){
        if(grid[i-1][j]==1&&visited[i-1][j]==0)
            c=dfs(i-1,j,grid,visited,c);
        if(j>0&&grid[i-1][j-1]==1&&visited[i-1][j-1]==0)
            c=dfs(i-1,j-1,grid,visited,c);
        if(j<m-1&&grid[i-1][j+1]==1&&visited[i-1][j+1]==0)
            c=dfs(i-1,j+1,grid,visited,c);
    }
    if(j>0){
        if(grid[i][j-1]==1&&visited[i][j-1]==0)
            c=dfs(i,j-1,grid,visited,c);
    }
    if(i<n-1){
        if(grid[i+1][j]==1&&visited[i+1][j]==0)
            c=dfs(i+1,j,grid,visited,c);
        if(j>0&&grid[i+1][j-1]==1&&visited[i+1][j-1]==0)
            c=dfs(i+1,j-1,grid,visited,c);
        if(j<m-1&&grid[i+1][j+1]==1&&visited[i+1][j+1]==0)
            c=dfs(i+1,j+1,grid,visited,c);
    }
    if(j<m-1){
        if(grid[i][j+1]==1&&visited[i][j+1]==0)
            c=dfs(i,j+1,grid,visited,c);
    }
    return c;
}
int maxRegion(vector<vector<int>> grid) {
    int n=grid.size();
    int m=grid[0].size();
    
    vector<vector<int>> visited(n,vector<int>(m,0));
    int maxsize=0,count;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1&&visited[i][j]==0){
                count=dfs(i,j,grid,visited,0);
                if(maxsize<count)
                    maxsize=count;
            }
        }
    }
    return maxsize;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid);

    fout << res << "\n";

    fout.close();

    return 0;
}
