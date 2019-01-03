#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 1000000007
#define ll long long
bool valid(int i,int j,int n,int m){
	if(i>=0&&i<n&&j>=0&&j<m){
		return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(true);
	int t,n,m;
	cin>>t;
	int di[8]={-1,-1,-1,0,1,1,1,0},dj[8]={-1,0,1,1,1,0,-1,-1};
	while(t--){
		cin>>n>>m;
		int arr[n][m];
		bool visited[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
				visited[i][j]=false;
			}
		}
		int count,max_count=INT_MIN;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j]==1&&!visited[i][j]){
					count=0;
					queue<pair<int,int> > Q;
					Q.push(make_pair(i,j));
					count++;
					visited[i][j]=true;
					while(!Q.empty()){
						int x=Q.front().first,y=Q.front().second;
						Q.pop();
						for(int k=0;k<8;k++){
							int nx=x+di[k],ny=y+dj[k];
							if(valid(nx,ny,n,m)){
								if(arr[nx][ny]==1&&!visited[nx][ny]){
									Q.push(make_pair(nx,ny));
									visited[nx][ny]=true;
									count++;
								}
							}
						}
					}
					max_count=max(max_count,count);
				}
			}
		}
		cout<<max_count<<endl;
	}
}