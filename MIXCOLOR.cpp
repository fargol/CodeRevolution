#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int main(){
	ios::sync_with_stdio(false);
	int T;
	int N,c;
	cin>>T;
	while(T--){
		cin>>N;
		vector<int> A(N);
		for(int &i:A)
			cin>>i;
		sort(A.begin(),A.end());
		c=0;
		for(int i=1;i<N;i++){
			if(A[i]==A[i-1])
				c++;
		}
		cout<<c<<endl;
	}
}