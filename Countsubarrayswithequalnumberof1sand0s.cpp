#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 1000000007
#define ll long long
int main(){
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		vector<int> arr(N+1,0);
		for(int i=1;i<N+1;i++){
			cin>>arr[i];
			if(arr[i]==0){
				arr[i]=-1;
			}
		}
		vector<int> cum_sum(N+1,0);
		for(int i=1;i<N+1;i++){
			cum_sum[i]=arr[i]+cum_sum[i-1];
		}
		unordered_map<int,int> hm;
		for(int i=0;i<N+1;i++){
			hm[cum_sum[i]]++;
		}
		int count=0;
		for(auto i=hm.begin();i!=hm.end();i++){
			count+=(i->second*(i->second-1))>>1;
		}
		cout<<count<<endl;
	}
}