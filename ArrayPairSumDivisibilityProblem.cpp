#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
inline bool check(vector<int> &arr,int k,int n){
	vector<int> mod(k,0);
	for(int i=0;i<n;i++)
		mod[arr[i]%k]++;
	if(mod[0]&1)
		return false;
	for(int i=1;i<k;i++){
		if(mod[i]!=mod[k-i])
			return false;
	}
	return true;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,n,k;
	cin>>T;
	vector<int> arr(100000);
	bool res;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		cin>>k;
		res=check(arr,k,n);
		if(res)
			cout<<"True\n";
		else
			cout<<"False\n";
	}
}