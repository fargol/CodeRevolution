#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

inline int set_room(vector<vector<int> > &arr,vector<vector<char> > &shape,int &N,int &M,int x,int y,int value){
	
	if(x-1>=0){
		if(arr[x-1][y]==0&&value>-1){
			shape[x-1][y]='Y';
			arr[x-1][y]=value;
			if(arr[x-1][y]>0&&shape[x])
				set_room(arr,shape,N,M,x-1,y,arr[x-1][y]-1);
		}
	}
	if(y-1>=0){
		if(arr[x][y-1]==0&&value>-1){
			shape[x][y-1]='Y';
			arr[x][y-1]=value;
			if(arr[x][y-1]>0)
				set_room(arr,shape,N,M,x,y-1,arr[x][y-1]-1);
		}
	}
	if(y+1<M){
		if(arr[x][y+1]==0&&value>-1){
			shape[x][y+1]='Y';
			arr[x][y+1]=value;
			if(arr[x][y+1]>0)
				set_room(arr,shape,N,M,x,y+1,arr[x][y+1]-1);
		}
	}
	if(x+1<N){
		if(arr[x+1][y]==0&&value>-1){
			shape[x+1][y]='Y';
			arr[x+1][y]=value;
			if(arr[x+1][y]>0)
				set_room(arr,shape,N,M,x+1,y,arr[x+1][y]-1);
		}
	}
}
int main(){
	int T;
	int N,M,k;
	cin>>T;
	vector<vector<int> > arr(1000,vector<int>(1000));
	vector<vector<char> > shape(1000,vector<char>(1000));
	vector<pair<int,int> > ep(1000);
	while(T--){
		cin>>N>>M;
		k=0;	
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				cin>>arr[i][j];
				if(arr[i][j]<0)
					shape[i][j]='B';
				else if(arr[i][j]==0)
					shape[i][j]='N';
				else{
					shape[i][j]='Y';
					ep[k].first=i;
					ep[k].second=j;
					k++;
				}
			}
		}
		for(int i=0;i<k;i++)
			set_room(arr,shape,N,M,ep[i].first,ep[i].second,arr[ep[i].first][ep[i].second]-1);
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++)
				cout<<shape[i][j];
			cout<<endl;
		}

		/*for(int i=0;i<N;i++){
			for(int j=0;j<M;j++)
				cout<<arr[i][j]<<" ";
			cout<<endl;
		}		
		for(int i=0;i<1000;i++){
				for(int j=0;j<1000;j++)
					shape[i][j]='\0';
			}*/
	}
}
