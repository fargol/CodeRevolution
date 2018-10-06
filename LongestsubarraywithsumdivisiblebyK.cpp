#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,K;
	cin>>T;
	while(T--){
		cin>>N>>K;
		int arr[N];
		int mod[N];
		int prefix_sum=0;
		for(int i=0;i<N;i++){
			cin>>arr[i];
			prefix_sum+=arr[i];
			mod[i]=(prefix_sum%K+K)%K;
		}
		unordered_map<int,int> hm;
		int maxS=0;
		for(int i=0;i<N;i++){
			if(mod[i]==0){
				maxS=i+1;
			}
			else if(hm.find(mod[i])==hm.end()){
				hm[mod[i]]=i;
			}
			else{
				maxS=max(maxS,i-hm[mod[i]]);
			}
		}
		cout<<maxS<<endl;
	}
}