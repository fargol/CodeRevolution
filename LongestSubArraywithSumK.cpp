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
		for(int &i:arr)
			cin>>i;
		unordered_map<int,int> hm;
		int sum=0,maxlen=0;
		for(int i=0;i<N;i++){
			sum+=arr[i];
			if(sum==K)
				maxlen=i+1;
			if(hm.find(sum)==hm.end())
				hm[sum]=i;
			if(hm.find(sum-K)!=hm.end()){
				maxlen=max(maxlen,i-hm[sum-K]);
			}
		}
		cout<<maxlen<<endl;
	}
}
