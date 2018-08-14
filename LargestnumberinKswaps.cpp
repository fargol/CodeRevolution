#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
void maxS(string S,int K,string &SS){
	if(K<=0)
		return;
	for(int i=0;i<S.length();i++){
		for(int j=i+1;j<S.length();j++){
			if(S[i]<S[j]){
				swap(S[i],S[j]);
				if(S.compare(SS)>0)
					SS=S;
				maxS(S,K-1,SS);
				swap(S[i],S[j]); //back-track
			}
		}
	}
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,K;
	string S,SS;
	cin>>T;
	while(T--){
		cin>>K;
		cin>>S;
		SS=S;
		maxS(S,K,SS);
		cout<<SS<<endl;
	}
}