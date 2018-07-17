#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(false);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		cout<<1<<" "<<1;
		if(N&1){
			N=(N-1)/2;
			while(N--)
				cout<<0;
		}
		else{
			N=N/2;
			while(N--)
				cout<<0;
		}
		cout<<endl;
	}
}