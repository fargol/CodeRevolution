#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define M 1000000007
int main(){
	ios::sync_with_stdio(true);
	int T,L,R;
	cin>>T;
	while(T--){
		cin>>L>>R;
		int count=0;
		bool isPrime[64];
		for(int i=0;i<64;i++)
			isPrime[i]=true;
		isPrime[0]=isPrime[1]=false;
		for(int i=2;i*i<64;i++){
			if(isPrime[i]){
				for(int j=2*i;j<64;j+=i){
					isPrime[j]=false;
				}
			}
		}
		for(int i=L;i<=R;i++){
			if(isPrime[__builtin_popcount(i)])
				count++;
		}
		cout<<count<<endl;
	}
}