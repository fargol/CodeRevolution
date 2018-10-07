#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
int main(){
	ios::sync_with_stdio(true);
	int T,N,K;
	cin>>T;
	while(T--){
		cin>>N>>K;
		int first=(N-(ceil(K/2.0)-1));
		cout<<first<<" ";
		for(int i=1;i<K;i++){
			if(i&1)
				cout<<0<<" ";
			else
				cout<<1<<" ";
		}
		cout<<endl;
	}
}