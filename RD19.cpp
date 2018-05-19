#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(false);
	int T,N,min,count;
	cin>>T;
	int arr[1001];
	while(T--){
		cin>>N;
		count=0;
		min=INT_MAX;
		for(int i=0;i<N;i++){
			cin>>arr[i];
			if(min>arr[i])
				min=arr[i];
		}
		if(min==1){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<N;i++){
			if(arr[i]%min==0)
				count++;
		}
		count--;
		if(count<N-1){
			cout<<count<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
}