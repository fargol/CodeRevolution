#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
#define ll long long
int main(){
	ios::sync_with_stdio(true);
	int T,R,C;
	cin>>T;
	while(T--){
		cin>>R>>C;
		int matrix[R][C];
		queue<pair<int,int> > Q;
		int fresh=0;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				cin>>matrix[i][j];
				if(matrix[i][j]==1){
					fresh++;
				}
				else if(matrix[i][j]==2){
					Q.push(make_pair(i,j));
				}
			}
		}

		Q.push(make_pair(R,C));
		int time=0;
		while(!Q.empty()){
			pair<int,int> pt=Q.front();
			Q.pop();
			int x=pt.first,y=pt.second;
			if(x==R&&y==C){
				time++;
				if(!Q.empty()){
					Q.push(pt);
				}
				else{
					continue;
				}
			}
			if(y+1<C&&matrix[x][y+1]==1){
				matrix[x][y+1]=2;
				Q.push(make_pair(x,y+1));
				fresh--;
			}
			if(x+1<R&&matrix[x+1][y]==1){
				matrix[x+1][y]=2;
				Q.push(make_pair(x+1,y));
				fresh--;
			}
			if(y-1>=0&&matrix[x][y-1]==1){
				matrix[x][y-1]=2;
				Q.push(make_pair(x,y-1));
				fresh--;
			}
			if(x-1>=0&&matrix[x-1][y]==1){
				matrix[x-1][y]=2;
				Q.push(make_pair(x-1,y));
				fresh--;
			}
		}
		if(fresh>0){
			cout<<-1<<endl;
		}
		else{
			cout<<time-1<<endl;
		}
	}
}