#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	long long int T,N,NN,max=LLONG_MIN;
	vector<int> primes(1000000,0);
	cin>>T;
	while(T--){
		cin>>N;
		NN=N;
		max=LLONG_MIN;
		for(long long int i=2;i<=pow(N,0.5);i++){
			if(NN%i==0){
				if(max<i)
					max=i;
			}
			while(NN%i==0){
				NN/=i;
			}
		}
		if(max<NN)
			max=NN;
		cout<<max<<endl;
	}
}