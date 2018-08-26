#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<long long int, long long int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<long long int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	long long int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		if(N>75){
			cout<<-1<<endl;
			continue;
		}
		long long int screen[N];
		for(long long int i=1;i<=6;i++)
			screen[i-1]=i;
		for(long long int i=7;i<=N;i++){
			screen[i-1]=0;
			for(long long int j=i-3;j>=1;j--){
				long long int curr=(i-j-1)*screen[j-1];
				if(curr>screen[i-1])
					screen[i-1]=curr;
			}
		}
		cout<<screen[N-1]<<endl;
	}
}