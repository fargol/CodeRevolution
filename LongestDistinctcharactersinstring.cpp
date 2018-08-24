#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T;
	string S;
	cin>>T;
	while(T--){
		cin>>S;
		unordered_map<char,int> hm;
		int l=0,h=0,maxl=INT_MIN;
		while(h<S.length()){
			if(hm.find(S[h])==hm.end()){
				//cout<<"\nU:: h = "<<h<<" & S[h] = "<<S[h]<<endl;
				hm[S[h]]=h;
				h++;
				maxl=max(maxl,h-l);
				//cout<<maxl<<endl;
			}
			else if(hm[S[h]]<l){
				hm[S[h]]=h;
				h++;
				maxl=max(maxl,h-l);
			}
			else{
				l=hm[S[h]]+1;
				hm[S[h]]=h;
				//cout<<"\nNU :: h = "<<h<<" & S[h] = "<<S[h]<<endl;
				h++;
				maxl=max(maxl,h-l);
				//cout<<maxl<<endl;
			}
		}
		cout<<maxl<<endl;
	}
}