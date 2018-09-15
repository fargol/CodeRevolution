#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
bool cmp(const pair<int,pair<int,int> > a,const pair<int,pair<int,int> > b){
	if(a.second.first<b.second.first)
		return false;
	else if(a.second.first==b.second.first){
		return a.second.second<b.second.second;
	}
	else
		return true;
}
bool cust_cmp(const pair<int,int> a,const pair<int,int> b){
	if(a.first<b.first)
		return false;
	else if(a.first==b.first){
		return a.second<b.second;
	}
	else
		return true;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		vector<pair<int,int> > A1(N),A2(N);
		vector<pair<int,pair<int,int> > > ans(N);
		for(int i=0;i<N;i++){
			cin>>A1[i].first;
			A1[i].second=i;
		}
		for(int i=0;i<N;i++){
			cin>>A2[i].first;
			A2[i].second=i;
		}
		sort(A1.begin(),A1.end(),cust_cmp);
		sort(A2.begin(),A2.end(),cust_cmp);
		int i=0,j=0,k=0;
		unordered_map<int,bool> hm;
		while(k<N){
			if(i<N&&j<N){
				if(A1[i].first>A2[j].first){
					if(hm.find(A1[i].first)==hm.end()){
						ans[k].first=A1[i].first;
						ans[k].second.first=1;
						ans[k].second.second=A1[i].second;
						k++;
						hm[A1[i].first]=true;
					}
					i++;
				}
				else{
					if(hm.find(A2[j].first)==hm.end()){
						ans[k].first=A2[j].first;
						ans[k].second.first=2;
						ans[k].second.second=A2[j].second;
						k++;
						hm[A2[j].first]=true;
					}
					j++;
				}
			}
			else if(i<N){
				if(hm.find(A1[i].first)==hm.end()){
					ans[k].first=A1[i].first;
					ans[k].second.first=1;
					ans[k].second.second=A1[i].second;
					k++;
					hm[A1[i].first]=true;
				}
				i++;
			}
			else{
				if(hm.find(A2[j].first)==hm.end()){
					ans[k].first=A2[j].first;
					ans[k].second.first=2;
					ans[k].second.second=A2[j].second;
					k++;
					hm[A2[j].first]=true;
				}
				j++;
			}
		}
		sort(ans.begin(),ans.end(),cmp);
		for(int i=0;i<N;i++){
			cout<<ans[i].first<<" ";
		}
		cout<<endl;
	}
}