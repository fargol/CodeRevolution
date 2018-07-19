#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,K,idx;
	bool flag;
	vector<int> arr(100005);
	cin>>T;
	while(T--){
		cin>>N;
		flag=false;
		for(int i=0;i<N;i++)
			cin>>arr[i];
		cin>>K;
		for(int i=0;i<N;i++){
			if(arr[i]==K){
				flag=true;
				idx=i;
				break;
			}
		}
		if(flag){
			cout<<idx<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
}