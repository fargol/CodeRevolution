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
		bool dp[S.length()+1]={false};
		vector<int> last_match;
		last_match.push_back(-1);
		for(int i=0;i<S.length();i++){
			int msize=last_match.size();
			bool flag=false;
			for(int j=msize-1;j>=0;j--){
				SS=S.substr(last_match[j]+1,i-last_match[j]);
				if(ump.find(SS)!=ump.end()){
					flag=true;
					break;
				}
			}
			if(flag){
				dp[i]=true;
				last_match.push_back(i);
			}
		}
		cout<<dp[S.length()-1]<<endl;
	}
}