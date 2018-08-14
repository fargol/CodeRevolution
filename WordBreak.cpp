#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	string dict[100],S,SS;
	while(T--){
		cin>>N;
		unordered_map<string,bool> ump;
		for(int i=0;i<N;i++){
			cin>>dict[i];
			ump[dict[i]]=true;
		}
		cin>>S;
		SS="";
		for(int i=0;i<S.length();i++){
			SS+=S[i];
			if(ump.find(SS)!=ump.end()){
				SS="";
			}
		}
		if(SS!=""){
			cout<<0<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}
}