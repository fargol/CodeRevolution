#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	string S;
	cin>>S;
	int n=S.length();
	int L[1000][1000];
	for(int i=0;i<n;i++)
		L[i][i]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<n-i+1;j++){
			int k=i+j-1;
			if(S[j]==S[k]){
				if(i==2)
					L[j][k]=2;
				else
					L[j][k]=L[j+1][k-1]+2;
			}
			else{
				L[j][k]=max(L[j][k-1],L[j+1][k]);
			}
		}
	}
	cout<<L[0][n-1]<<endl;
}