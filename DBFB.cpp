#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define MOD 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(false);
	int T,M,N;
	cin>>T;
	vector<long long int> fib(100010);
	vector<long long int> A(100010),B(100010);//uA(100010),uB(100010);
	long long int result,sumA,sumB;
	fib[0]=1;
	fib[1]=0;
	fib[2]=1;
	for(int i=3;i<=100010;i++){
		fib[i]=fib[i-1]%MOD;
		fib[i]+=fib[i-2]%MOD;
		fib[i]%=MOD;
	}
	while(T--){
		result=sumA=sumB=0;
		cin>>M>>N;
		for(int i=0;i<M;i++){
			cin>>A[i];
			sumA+=A[i];
			sumA%=MOD;
		}
		for(int i=0;i<M;i++){
			cin>>B[i];
			sumB+=B[i];
			sumB%=MOD;
		}
		sumA*=fib[N-1];
		sumA%=MOD;
		sumB*=fib[N];
		sumB%=MOD;
		result=sumA+sumB;
		result%=MOD;
		result*=M;
		result%=MOD;
		cout<<result<<endl;
	}
}