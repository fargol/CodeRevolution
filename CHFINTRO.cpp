#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
#define ll long long
int main(){
	ios::sync_with_stdio(true);
	int N,r,R;
	cin>>N>>r;
	for(int i=0;i<N;i++){
		cin>>R;
		if(R<r){
			cout<<"Bad boi\n";
		}
		else{
			cout<<"Good boi\n";
		}
	}
}