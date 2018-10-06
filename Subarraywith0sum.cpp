#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<long long int, long long int> ii; typedef vector<ii> vii;
bool check(long long int n){
	long long int arr[n];
	long long int presum=0;
	unordered_set<long long int> sumset;
	for(long long int i=0;i<n;i++){
		cin>>arr[i];
		presum+=arr[i];
		if(arr[i]==0||presum==0||sumset.find(presum)!=sumset.end())
			return true;
		sumset.insert(presum);
	}
	return false;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<long long int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	long long int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		if(check(n))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}