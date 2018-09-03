#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,arr[1100];
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>arr[i];
		sort(arr,arr+N);
		for(int i=0;i<N-1;i+=2){
			arr[i]=arr[i]^arr[i+1];
			arr[i+1]=arr[i]^arr[i+1];
			arr[i]=arr[i]^arr[i+1];
		}
		for(int i=0;i<N;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
}