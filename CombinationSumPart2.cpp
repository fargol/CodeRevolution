#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
inline void getSolutions(int *arr,int start,int N,int B,vector<vector<int> > &vsol,vector<int> &sol){
	if(B==0){
		vsol.push_back(sol);
	}
	if(B<0||start>=N)
		return;
	for(int i=start+1;i<N&&B>=arr[i];i++){
		if(i>start+1&&arr[i-1]==arr[i])
			continue;
		sol.push_back(arr[i]);
		getSolutions(arr,i,N,B-arr[i],vsol,sol);
		sol.pop_back(); //backtrack
	}
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,B;
	cin>>T;
	while(T--){
		cin>>N;
		int arr[N];
		for(int &i:arr)
			cin>>i;
		sort(arr,arr+N);
		cin>>B;
		vector<vector<int> > vsol;
		vector<int> sol;
		for(int i=0;i<N;i++){
			if(i>0&&arr[i]==arr[i-1])
				continue;
			sol.push_back(arr[i]);
			getSolutions(arr,i,N,B-arr[i],vsol,sol);
			sol.pop_back(); //backtrack
		}
		if(vsol.size()==0){
			cout<<"Empty\n";
			continue;
		}
		for(int i=0;i<vsol.size();i++){
			cout<<'(';
			for(int j=0;j<vsol[i].size()-1;j++)
				cout<<vsol[i][j]<<' ';
			cout<<vsol[i][vsol[i].size()-1]<<')';
		}
		cout<<endl;
	}	
}