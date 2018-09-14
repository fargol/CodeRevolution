#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
string sequence(int N,int D){
	unordered_map<int,int> hm;
	string res="";
	int R=N%D;
	if(R==0)
		return to_string(N/D);
	while((R!=0)&&(hm.find(R)==hm.end())){
		hm[R]=res.length();
		R*=10;
		res+=to_string(R/D);
		R%=D;
	}
	string ans=to_string(N/D)+'.';
	if(R==0){
		ans+=res;
		return ans;
	}
	ans+=res.substr(0,hm[R]);
	if(R!=0)
		ans+=("("+res.substr(hm[R])+")");
	return ans;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,D;
	cin>>T;
	while(T--){
		cin>>N>>D;
		cout<<sequence(N,D)<<endl;
	}
}