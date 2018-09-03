#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	long long int count=0,sum_n;
	cin>>T;
	while(T--){
		cin>>N;
		count=0;
		for(int i=1;i<=N;i++){
			//cout<<"val = "<<pow(N-i+1,2)<<endl;
			count+=pow(N-i+1,2);
		}
		sum_n=(N*(N+1))/2;
		count=pow(sum_n,2)-count;
		cout<<count<<endl;
	}
}