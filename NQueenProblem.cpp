#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
inline void printSol(vector<int> &Sol,int N){
	cout<<"[";
	for(int i=1;i<=N;i++)
		cout<<Sol[i]<<" ";
	cout<<"] ";
}
inline bool isSafe(int r,int c,vector<int> &Sol,int N){
	int i,j;
	for(i=1;i<c;i++){
		if(Sol[i]==r)
			return false;
	}
	for(i=r-1,j=c-1;i>=1&&j>=1;i--,j--){
		if(Sol[j]==i)
			return false;
	}
	for(i=r+1,j=c-1;i<=N&&j>=1;i++,j--){
		if(Sol[j]==i)
			return false;
	}
	return true;
}
inline bool getSolutions(int N,int col,vector<int> &Sol){
	if(col>N){
		printSol(Sol,N);
		return true;
	}
	bool res=false;
	for(int i=1;i<=N;i++){
		if(isSafe(i,col,Sol,N)){
			Sol[col]=i;
			res=getSolutions(N,col+1,Sol)||res;
			Sol[col]=0;
		}
	}
	return res;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		vector<int> sol(N+1,0);
		if(!getSolutions(N,1,sol))
			cout<<-1;
		cout<<endl;
	}		
}