#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 1000000007
#define ll long long
int main(){
	ios::sync_with_stdio(true);
	int T;
	cin>>T;
	while(T--){
		int N1,N2,N3;
		cin>>N1>>N2>>N3;
		vector<int> A(N1),B(N2),C(N3);
		for(int &i:A){
			cin>>i;
		}
		for(int &i:B){
			cin>>i;
		}
		for(int &i:C){
			cin>>i;
		}
		int i=0,j=0,k=0;
		bool flag=false;
		while(i<N1&&j<N2&&k<N3){
			if(A[i]==B[j]&&B[j]==C[k]){
				cout<<A[i]<<" ";
				flag=true;
				i++;
				j++;
				k++;
			}
			else if(A[i]<B[j]){
				i++;
			}
			else if(B[j]<C[k]){
				j++;
			}
			else{
				k++;
			}
		}
		if(!flag){
			cout<<-1;
		}
		cout<<endl;
	}
}