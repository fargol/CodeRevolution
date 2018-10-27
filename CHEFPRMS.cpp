#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
inline bool func(int N,bool isSemiPrime[]){
	for(int i=1;i<N;i++){
		int j=N-i;
		if(isSemiPrime[i]&&isSemiPrime[j]){
			return true;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(true);
	bool isPrime[250];
	//memset(isPrime,true,sizeof(isPrime[0]));
	for(int i=0;i<250;i++)
		isPrime[i]=true;
	isPrime[0]=isPrime[1]=false;
	for(int i=2;i*i<250;i++){
		if(isPrime[i]){
			for(int j=2*i;j<250;j+=i){
				isPrime[j]=false;
			}
		}
	}
	bool isSemiPrime[250];
	//memset(isSemiPrime,false,250*sizeof(isSemiPrime[0]));
	for(int i=0;i<250;i++)
		isSemiPrime[i]=false;
	for(int i=0;i<250;i++){
		if(isPrime[i]){
			for(int j=i+1;i*j<250;j++){
				if(isPrime[j]){
					isSemiPrime[i*j]=true;
				}
			}
		}
	}
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		if(func(N,isSemiPrime)){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}