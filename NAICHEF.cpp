#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(false);
	int T,N,A,B,cA,cB,n;
	double pA,pB,p;
	cin>>T;
	while(T--){
		cin>>N>>A>>B;
		cA=cB=0;
		for(int i=0;i<N;i++){
			cin>>n;
			if(n==A)
				cA++;
			if(n==B)
				cB++;
		}
		pA=(cA*1.0)/(N*1.0);
		pB=(cB*1.0)/(N*1.0);
		p=pA*pB;
		printf("%.6f\n",p);
	}
}