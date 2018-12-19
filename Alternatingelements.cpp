#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define M 1000000007;
#define ll long long
int main(){
	ios::sync_with_stdio(true);
	int T,N,M;
	cin>>T;
	while(T--){
		cin>>N>>M;
		vector<int> A(N);
		vector<int> B(M);
		for(int &i:A)
			cin>>i;
		for(int &i:B)
			cin>>i;
		for(int i=0;i<max(N,M);i++){
			if(0<=i&&i<N){
				cout<<A[i]<<" ";
			}
			if(0<=i&&i<M){
				cout<<B[i]<<" ";
			}
		}
		cout<<endl;
	}
}