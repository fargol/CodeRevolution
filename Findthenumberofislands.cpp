{
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000  
int findIslands(int A[MAX][MAX],int N,int M);
int main() {
	// your code goes here
	int T;
	cin>>T;
	int A[MAX][MAX];
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		memset(A,0,sizeof A);
		for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		cin>>A[i][j];
		cout<<findIslands(A,N,M)<<endl;
	}
	return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*you are required to complete this method*/
void dfs(vector<vector<bool> > &visited,int i,int j,int N,int M,int A[MAX][MAX]){
    visited[i][j]=true;//1
    if(i>0){
        if(A[i-1][j]&&!visited[i-1][j])
            dfs(visited,i-1,j,N,M,A);//2
        if(j>0){
            if(A[i-1][j-1]&&!visited[i-1][j-1])
                dfs(visited,i-1,j-1,N,M,A);//3
        }
        if(j<M-1){
            if(A[i-1][j+1]&&!visited[i-1][j+1])
                dfs(visited,i-1,j+1,N,M,A);//4
        }
    }
    if(i<N-1){
        if(A[i+1][j]&&!visited[i+1][j])
            dfs(visited,i+1,j,N,M,A);//5
        if(j>0){
            if(A[i+1][j-1]&&!visited[i+1][j-1])
                dfs(visited,i+1,j-1,N,M,A);//6
        }
        if(j<M-1){
            if(A[i+1][j+1]&&!visited[i+1][j+1])
                dfs(visited,i+1,j+1,N,M,A);//7
        }
    }
    if(j>0){
        if(A[i][j-1]&&!visited[i][j-1])
            dfs(visited,i,j-1,N,M,A);//8
    }
    if(j<M-1){
        if(A[i][j+1]&&!visited[i][j+1])
            dfs(visited,i,j+1,N,M,A);//9
    }
}
int findIslands(int A[MAX][MAX], int N, int M)
{
    //Your code here 
    vector<vector<bool> > visited(N,vector<bool>(M));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            visited[i][j]=false;
    }
    int count=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(A[i][j]==0)
                continue;
            if(!visited[i][j]){
                count++;
                dfs(visited,i,j,N,M,A);
                //printf("i = %d :: j = %d :: A = %d\n",i,j,A[i][j]);
            }
        }
    }
    return count;
}