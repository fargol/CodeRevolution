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
	long long int a[110],b[110],res;
	a[1]=b[1]=1;
	for(int i=2;i<110;i++){
		a[i]=a[i-1]+b[i-1];
		a[i]%=M;
		b[i]=a[i-1];
	}
	cin>>T;
	while(T--){
		cin>>N;
		res=a[N]+b[N];
		res%=M;
		cout<<res<<endl;
	}
}