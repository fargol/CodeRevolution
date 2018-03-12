#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int main(){
	ios::sync_with_stdio(false);
	int T;
	int N,f,b;
	cin>>T;
	while(T--){
		cin>>N;
		vector<int> L(N);
		vector<int> G(N);
		for(int &i:L)
			cin>>i;
		for(int &i:G)
			cin>>i;
		f=b=1;
		for(int i=0;i<N;i++){
			if(L[i]>G[i])
				f=0;
			if(L[i]>G[N-i-1])
				b=0;
		}
		if(f==b){
			if(f==0){
				cout<<"none"<<endl;
			}
			else{
				cout<<"both"<<endl;
			}
		}
		else{
			if(f==1){
				cout<<"front"<<endl;
			}
			else{
				cout<<"back"<<endl;
			}
		}
	}
}