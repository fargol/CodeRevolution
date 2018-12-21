#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 1000000007
#define ll long long
bool isBleak(int N){
	for(int i=0;i<min(33,N);i++){
		int x=N-i;
		if(__builtin_popcount(x)==i)
			return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		cout<<isBleak(N)<<endl;
	}
}