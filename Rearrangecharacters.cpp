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
	int maxF,sumF;
	while(T--){
		cin>>S;
		vector<int> freq(26,0);
		maxF=sumF=0;
		for(int i=0;i<S.length();i++){
			freq[S[i]-'a']++;
			maxF=max(maxF,freq[S[i]-'a']);
		}
		sumF=S.length();
		sumF-=maxF;
		if(maxF>sumF+1){
			cout<<0<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}
}