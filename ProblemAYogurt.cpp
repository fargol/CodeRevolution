#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,K,day,count,total_c;
	int A[9999];
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>N>>K;
		for(int i=0;i<N;i++)
			cin>>A[i];
		sort(A,A+N);
		day=0;
		count=0;
		total_c=0;
		for(int i=0;i<N;i++){
			if(day<A[i]){
				count++;
				//cout<<"A[i] = "<<A[i]<<" ";
			}
			if(count==K){
				day++;
				total_c+=count;
				count=0;
			}
		}
		total_c+=count;
		printf("Case #%d: %d\n",t,total_c);
	}
}