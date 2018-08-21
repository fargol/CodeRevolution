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
	vector<long long int> dpA(100001),dpB(100001);
	long long int res;
	dpA[0]=dpB[0]=0;
	dpA[1]=dpB[1]=1;
	for(int i=2;i<100001;i++){
		dpA[i]=dpA[i-1]+dpB[i-1];
		dpA[i]%=M;
		dpB[i]=dpA[i-1]%M;
		dpB[i]%=M;
	}
	cin>>T;
	while(T--){
		cin>>N;
		res=dpA[N]+dpB[N];
		res%=M;
		res*=res;
		res%=M;
		cout<<res<<endl;
	}
}