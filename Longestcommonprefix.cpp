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
	cin>>T;
	string S1,S2;
	while(T--){
		cin>>S1>>S2;
		int maxlen=INT_MIN,idx,i=0,j=0,maxIdx;
		while(j<S2.length()){
			if(S2[j]==S1[0]){
				idx=j;
				i=0;
				while(i<S1.length()&&j<S2.length()&&S2[j]==S1[i]){
					j++;
					i++;
				}
				if(maxlen<i){
					maxlen=i;
					maxIdx=idx;
				}
			}
			else
				j++;
		}
		if(maxlen>INT_MIN){
			cout<<maxIdx<<" "<<S1.substr(0,maxlen)<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
}