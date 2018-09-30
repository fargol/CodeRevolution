#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T;
	cin>>T;
	while(T--){
		unsigned long long int N,Num=0,eval; 
		cin>>N;
		for(int i=0;i<=63;i++){
			if(N>>i&1){
			    eval=1;
				for(int j=1;j<=i;j++)
				    eval*=7;
				Num+=eval;
			}
		}
		cout<<Num<<endl;
	}
}