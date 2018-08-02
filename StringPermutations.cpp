#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T;
	cin>>T;
	string S;
	while(T--){
		cin>>S;
		sort(S.begin(),S.end());
		do{
			cout<<S<<endl;
		}while(next_permutation(S.begin(),S.end()));
	}
}