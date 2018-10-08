#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
int main(){
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		bool isPrime[N+1];
		memset(isPrime,true,(N+1)*sizeof(isPrime[0]));
		isPrime[0]=isPrime[1]=false;
		for(int i=2;i*i<=N;i++){
			if(isPrime[i]){
				for(int j=2*i;j<=N;j+=i){
					isPrime[j]=false;
				}
			}
		}
		for(int i=2;i<=N;i++){
			for(int j=2;j<=N;j++){
				if(isPrime[i]&isPrime[j]){
					if(i*j<=N)
						cout<<i<<" "<<j<<" ";
				}
			}
		}
		cout<<endl;
	}
}