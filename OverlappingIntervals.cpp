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
	int T,N,x,y;
	cin>>T;
	while(T--){
		cin>>N;
		vector<pair<int,int> > arr(N);
		for(int i=0;i<N;i++){
			cin>>arr[i].first>>arr[i].second;
		}
		sort(arr.begin(),arr.end());
		vector<pair<int,int> > res;
		int b=arr[0].first,e=arr[0].second;
		for(int i=1;i<N;i++){
			if(arr[i].first<=e){
				e=max(e,arr[i].second);
			}
			else{
				res.push_back(make_pair(b,e));
				b=arr[i].first;
				e=arr[i].second;
			}
		}
		res.push_back(make_pair(b,e));
		for(int i=0;i<res.size();i++)
			cout<<res[i].first<<" "<<res[i].second<<" ";
		cout<<endl;
	}
}