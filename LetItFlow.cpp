#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
#define M 1000000007;
inline long long int numberOfPaths(string &R1,string &R2,string &R3,int &N){
	long long int count=1;
	if(N&1)
		return 0;
	if(R1[0]=='#'||R2[0]=='#'||R2[1]=='#'||R3[N-1]=='#'||R2[N-1]=='#'||R2[N-2]=='#')
		return 0LL;
	int way;
	for(int i=1;i<N-2;i+=2){
		way=0;
		if(R2[i]=='.'&&R2[i+1]=='.'){
			if(R1[i]=='.'&&R1[i+1]=='.')
				way++;
			if(R3[i]=='.'&&R3[i+1]=='.')
				way++;
		}
		count*=way;
		count%=M;
	}
	//count%=M;
	return count;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	long long int count;
	string R1,R2,R3;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>N;
		cin>>R1>>R2>>R3;
		count=numberOfPaths(R1,R2,R3,N);
		printf("Case #%d: %lld\n",i,count);
	}
}