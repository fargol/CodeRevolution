#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	vector<bool> primes(10010,true);
	primes[0]=primes[1]=false;
	for(int i=2;i*i<10010;i++){
		if(primes[i]){
			for(int j=2*i;j<10010;j+=i)
				primes[j]=false;
		}
	}
	while(T--){
		cin>>N;
		for(int i=0;i<=N;i++){
			if(primes[i]&&primes[N-i]){
				if(i<=N-i){
					cout<<i<<" "<<N-i<<endl;
				}
				else{
					cout<<N-i<<" "<<i<<endl;
				}
				break;
			}
		}
	}
}