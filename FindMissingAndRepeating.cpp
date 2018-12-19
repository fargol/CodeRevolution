#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
#define ll long long
int main(){
	ios::sync_with_stdio(true);
	int T,N,sumA,sum,X,Xa,a,b;
	cin>>T;
	while(T--){
		cin>>N;
		sumA=sum=0;
		vector<int> A(N);
		X=Xa=0;
		for(int i=0;i<N;i++){
			sum+=(i+1);
			X^=(i+1);
			cin>>A[i];
			Xa^=A[i];
			sumA+=A[i];
		}
		sort(A.begin(),A.end());
		for(int i=1;i<N;i++){
			if(A[i]==A[i-1]){
				a=A[i];
				break;
			}
		}
		X^=Xa;
		b=X^a;
		cout<<a<<" "<<b<<endl;
	}
}