#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
inline long long int modular_exp(long long int num,long long int exp){
	long long int res=1;
	num%=M;
	while(exp>0){
		if(exp&1){
			res=(1LL*res*num)%M;
			res%M;
		}
		exp=exp>>1;
		num=(1LL*num*num)%M;
		num%=M;
	}
	res%=M;
	return res;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int n,k;
	long long int val,res,ag1;
	cin>>n>>k;
	if(n==2){
		cout<<0<<endl;
	}
	else{
		ag1=M+1;
		ag1>>=1;
		res=1LL*n*modular_exp(ag1,n-1);
		res%=M;
		val=1-res;
		val+=M;
		val%=M;
		cout<<val<<endl;
	}
}