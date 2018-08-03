#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,Q,x,y;
	cin>>T;
	string command;
	while(T--){
		cin>>N>>Q;
		list<pair<int,int> > L;
		unordered_map <int,int> mp;
		while(Q--){
			cin>>command;
			if(command=="SET"){
				cin>>x>>y;
				if(L.size()<N){
					L.push_front(make_pair(x,y));
					mp[x]=y;
				}
				else{
					pair<int,int> temp=L.back();
					mp.erase(temp.first);
					L.pop_back();
				}
			}
			else{
				cin>>x;
				if(mp.find(x)!=mp.end()){
					cout<<mp[x]<<" ";
				}
				else{
					cout<<"-1 ";
				}
			}
		}
		cout<<endl;
	}
}