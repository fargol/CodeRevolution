#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
#define ll long long
int main(){
	ios::sync_with_stdio(true);
	ll int T,N,NN;
	cin>>T;
	while(T--){
		cin>>N;
		if(0<=N&&N<=9){
			cout<<N<<endl;
			continue;
		}
		NN=N;
		vector<ll int> fact(10,0);
		for(ll int i=9;i>=2;i--){
			while(NN%i==0&&NN>0){
				NN/=i;
				fact[i]++;
			}
		}
		if(NN>1){
			cout<<-1<<endl;
			continue;
		}
		string res="";
		for(ll int i=2;i<=9;i++){
			for(ll int j=0;j<fact[i];j++)
				res+=to_string(i);
		}
		cout<<res<<endl;
	}
}
