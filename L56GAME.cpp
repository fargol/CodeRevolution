#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int main(){
	int T,N,A,odd;
	cin>>T;
	while(T--){
		cin>>N;
		A=odd=0;
		while(N--){
			cin>>A;
			if(A&1)
				odd++;
		}
		if(odd%2==0)
			cout<<"1\n";
		else
			cout<<"2\n";
	}
}
