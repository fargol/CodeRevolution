#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 1000000007
#define ll long long
long long int gcd(long long int a,long long int b){
	if(a%b==0){
		return b;
	}
	else if(b%a==0){
		return a;
	}
	else{
		return gcd(b%a,a);
	}
}
int main(){
	ios::sync_with_stdio(true);
	long long int T,a,b;
	cin>>T;
	while(T--){
		cin>>a>>b;
		long long int k=gcd(a,b);
		long long int n=(a*b)/(k*k);
		cout<<n<<" "<<k<<endl;
	}
}