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
		int A[N];
		for(int &i:A)
			cin>>i;
		unordered_map<int,int> hm;
		for(int i=0;i<N;i++){
			if(hm.find(A[i])==hm.end()){
				hm[A[i]]=1;
			}
			else{
				hm[A[i]]++;
			}
		}
		int count=0;
		for(int i=0;i<N;i++){
			if(A[i]<<1==K){
				count+=hm[A[i]]-1;
			}
			else if(hm.find(K-A[i])!=hm.end()){
				count+=hm[K-A[i]];
			}
		}
		count>>=1;
		cout<<count<<endl;
	}
}