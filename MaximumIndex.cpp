#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(false);
	int T,N,min,max_diff;
	cin>>T;
	while(T--){
		cin>>N;
		vector<pair<int,int> > arr(N);
		for(int i=0;i<N;i++){
			cin>>arr[i].first;
			arr[i].second=i;
		}
		sort(arr.begin(),arr.end());
		min=INT_MAX;
		max_diff=INT_MIN;
		for(int i=0;i<N;i++){
			if(min>arr[i].second){
				min=arr[i].second;
			}
			if(arr[i].second-min>max_diff)
				max_diff=arr[i].second-min;
		}
		cout<<max_diff<<endl;
	}
}