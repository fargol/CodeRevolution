#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int main(){
	ios::sync_with_stdio(true);
	int T,N;
	long long int bits,nibbles,bytes,exp,rem,entity;
	cin>>T;
	while(T--){
		cin>>N;
		N--;
		bits=1;
		exp=N/26;
		rem=N%26;
		entity=pow(2,exp);
		if(rem<2){
			bits=entity;
			nibbles=0;
			bytes=0;
		}
		else if(rem<10){
			bits=0;
			nibbles=entity;
			bytes=0;
		}
		else{
			bits=0;
			nibbles=0;
			bytes=entity;
		}
		cout<<bits<<" "<<nibbles<<" "<<bytes<<endl;
	}
}