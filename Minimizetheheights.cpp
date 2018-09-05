#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,K,N,A[40];
	cin>>T;
	while(T--){
		cin>>K>>N;
		for(int i=0;i<N;i++){
			cin>>A[i];
		}
		sort(A,A+N);
		int min_diff=A[N-1]-A[0];
		int minE=A[0]+K;
		int maxE=A[N-1]-K;
		if(minE>maxE){
			int temp=minE;
			minE=maxE;
			maxE=temp;
		}
		for(int i=1;i<N-1;i++){
			int add=A[i]+K;
			int sub=A[i]-K;
			if(add<=maxE||sub>=minE)
				continue;
			if(maxE-sub<add-minE)
				minE=sub;
			else
				maxE=add;
		}
		cout<<min(min_diff,maxE-minE)<<endl;
	}		
}