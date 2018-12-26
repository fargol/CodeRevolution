#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 1000000007
#define ll long long
// bool isPossible(vector<pair<ll int,ll int> > CumSched,pair<ll int,ll int> i){
// 	ll int low=0,high=CumSched.size()-1,mid;
// 	if(i.first<CumSched[low].first){
// 		return false;
// 	}
// 	if(i.first>CumSched[high].first){
// 		if(CumSched[high].second>=i.second){
// 			return true;
// 		}
// 		else{
// 			return false;
// 		}
// 	}
// 	while(low<high){
// 		mid=(low+high)>>1;
// 		if(CumSched[mid].first<=i.first){
// 			if(CumSched[mid].second>=i.second){
// 				return true;
// 			}
// 			else{
// 				low=mid+1;
// 			}
// 		}
// 		else{
// 			high=mid-1;
// 		}
// 	}
// 	return false;
// }
int main(){
	ios::sync_with_stdio(true);
	ll int T,D,Q,x,y;
	cin>>T;
	while(T--){
		cin>>D;
		vector<ll int> CumSched(32);
		for(ll int i=0;i<D;i++){
			cin>>x>>y;
			CumSched[x]=y;
		}
		for(ll int i=2;i<32;i++){
			CumSched[i]+=CumSched[i-1];
		}
		// cout<<"CumSched => "<<endl;
		// for(ll int i=1;i<32;i++){
		// 	cout<<i<<" - "<<CumSched[i]<<endl;
		// }
		cin>>Q;
		for(ll int i=0;i<Q;i++){
			cin>>x>>y;
			if(CumSched[x]>=y){
				cout<<"Go Camp\n";
			}
			else{
				cout<<"Go Sleep\n";
			}
		}
	}
}