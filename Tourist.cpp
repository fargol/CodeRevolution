#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	long long int T,K,N,V,idx;
	cin>>T;
	vector<string> arr(50);
	vector<int> indices(50);
	for(int j=1;j<=T;j++){
		cin>>N>>K>>V;
		for(int i=0;i<N;i++)
			cin>>arr[i];
		idx=K*(V-1);
		idx%=N;
		cout<<"Case #"<<j<<": ";
		for(int i=0;i<K;i++){
			indices[i]=idx%N;
			idx++;
		}
		sort(indices.begin(),indices.begin()+K);
		for(int i=0;i<K;i++)
			cout<<arr[indices[i]]<<" ";
		cout<<endl;
	}	
}