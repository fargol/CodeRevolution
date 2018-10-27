#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
struct CIRCLE{
	ll int X,Y,R;
};
bool cmp(const pair<long double,long double> a,
	const pair<long double,long double> b){
	return a.second<b.second;
}
int main(){
	ios::sync_with_stdio(true);
	ll int T,N,Q,X,Y,R,K;
	//cin>>T;
	CIRCLE circles[1001];
	vector<pair<long double,long double> > distances1(10000001);
	vector<pair<long double,long double> > distances2(10000001);
	//while(T--){
		cin>>N>>Q;
		for(ll int i=0;i<N;i++)
			cin>>circles[i].X>>circles[i].Y>>circles[i].R;
		ll int k=0;
		for(ll int i=0;i<N;i++){
			for(ll int j=i+1;j<N;j++){
				distances1[k].first=pow(circles[i].X-circles[j].X,2);
				distances1[k].first+=pow(circles[i].Y-circles[j].Y,2);
				distances1[k].first=sqrt(distances1[k].first);
				distances1[k].first-=circles[i].R;
				distances1[k].first-=circles[j].R;
				distances1[k].second=pow(circles[i].X-circles[j].X,2);
				distances1[k].second+=pow(circles[i].Y-circles[j].Y,2);
				distances1[k].second=sqrt(distances1[k].second);
				distances1[k].second+=circles[i].R;
				distances1[k].second+=circles[j].R;
				distances2[k]=distances1[k];
				k++;
			}
		}
		sort(distances1.begin(),distances1.begin()+k);
		sort(distances2.begin(),distances2.begin()+k,cmp);
		while(Q--){
			cin>>K;
			ll int low=0,high=k-1,mid,lower_l,greater_r,res;
			while(low<=high){
				mid=(low+high)/2;
				if(distances1[mid].first<=K){
					low=mid+1;
				}
				else{
					high=mid-1;
				}
			}
			while(mid>=0&&distances1[mid].first>K)
				mid--;
			lower_l=mid+1;
			low=0;
			high=k-1;
			while(low<=high){
				mid=(low+high)/2;
				if(distances2[mid].second<=K){
					low=mid+1;
				}
				else{
					high=mid-1;
				}
			}
			while(mid<k&&distances2[mid].second<K)
				mid++;
			greater_r=k-mid-1;
			res=greater_r+lower_l;
			res-=k;
			res++;
			cout<<res<<endl;
		}
	//}
}