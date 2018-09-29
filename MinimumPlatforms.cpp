#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
bool cmp(const pair<int,int> a,const pair<int,int> b){
	return a.second<b.second;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		multimap<int,char> mp;
		int time;
		for(int i=0;i<N;i++){
			cin>>time;
			mp.insert(make_pair(time,'a'));
		}
		for(int i=0;i<N;i++){
			cin>>time;
			mp.insert(make_pair(time,'d'));
		}
		int count=0,maxcount=INT_MIN;
		for(auto i=mp.begin();i!=mp.end();i++){
			if(i->second=='a')
				count++;
			else
				count--;
			if(count>maxcount)
				maxcount=count;
		}
		cout<<maxcount<<endl;
	}
}