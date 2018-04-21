#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<long long int, long long int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<long long int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	long long int T,A,B,N,res;
	cin>>T;
	while(T--){
		cin>>A>>B>>N;
		A++;
		string verdict="NA";
		while(verdict!="CORRECT"&&N){
			res=(A+B)/2;
			cout<<res<<endl;
			cin>>verdict;
			if(verdict=="TOO_BIG")
				B=res-1;
			else if(verdict=="TOO_SMALL")
				A=res+1;
			N--;
		}
	}
}