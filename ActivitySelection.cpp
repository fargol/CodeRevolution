#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,N,count;
	cin>>T;
	while(T--){
		cin>>N;
		vector<pair<int,int> > tt(N);
		for(int i=0;i<N;i++)
			cin>>tt[i].second;
		for(int i=0;i<N;i++)
			cin>>tt[i].first;
		sort(tt.begin(),tt.end());
		count=1;
		int prev=tt[0].first;
		for(int i=1;i<N;i++){
			if(tt[i].second>=prev){
				count++;
				prev=tt[i].first;
			}
		}
		cout<<count<<endl;
	}
}