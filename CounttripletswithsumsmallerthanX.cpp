#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,X;
	cin>>T;
	while(T--){
		cin>>N>>X;
		int A[N];
		for(int &i:A)
			cin>>i;
		sort(A,A+N);
		int count=0,Y;
		for(int i=0;i<N;i++){
			int j=i+1,k=N-1;
			Y=X-A[i];
			while(j<k){
				if(A[j]+A[k]<Y){
					count+=k-j;
					j++;
				}
				else{
					k--;
				}
			}
		}
		cout<<count<<endl;
	}
}