#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	long long int T,P1,P2,K;
	cin>>T;
	while(T--){
		cin>>P1>>P2>>K;
		P1+=P2;
		P1/=K;
		if(P1&1)
			cout<<"COOK\n";
		else
			cout<<"CHEF\n";
	}
}