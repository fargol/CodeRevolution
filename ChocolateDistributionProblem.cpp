#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,n,arr[5000],m,min_diff;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cin>>m;
		sort(arr,arr+n);
		min_diff=INT_MAX;
		for(int i=m-1;i<n;i++){
			if(min_diff>arr[i]-arr[i-m+1])
				min_diff=arr[i]-arr[i-m+1];
		}
		cout<<min_diff<<endl;
	}
}