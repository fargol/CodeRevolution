#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 1000000007
#define ll long long
int main(){
	ios::sync_with_stdio(true);
	int T,N,Q,type,K,I;
	string S,temp1,temp2;
	cin>>T;
	while(T--){
		cin>>N>>Q;
		cin>>S;
		while(Q--){
			cin>>type;
			if(type==1){
				cin>>K;
				K%=N;
				temp1=S.substr(N-K);
				temp2=S.substr(0,N-K);
				S=temp1+temp2;
			}
			else{
				cin>>I;
				I%=N;
				cout<<S[I]<<endl;
			}
		}
	}
}