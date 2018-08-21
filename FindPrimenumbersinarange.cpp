#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,n,m;
	cin>>T;
	vector<bool> isPrime(100001,true);
	isPrime[0]=isPrime[1]=false;
	for(int i=2;i*i<100001;i++){
		if(isPrime[i]){
			for(int j=2*i;j<100001;j+=i){
				isPrime[j]=false;
			}
		}
	}
	while(T--){
		cin>>m>>n;
		for(int i=m;i<=n;i++){
			if(isPrime[i])
				cout<<i<<" ";
		}
		cout<<endl;
	}
}