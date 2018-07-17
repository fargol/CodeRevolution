#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,c_o,c_e;
	string S;
	cin>>T;
	while(T--){
		cin>>S;
		c_o=0;
		c_e=0;
		for(int i=0;i<S.length();i++){
			if(i&1){
				if(S[i]=='1')
					c_o++;
			}
			else{
				if(S[i]=='1')
					c_e++;
			}
		}
		if(abs(c_o-c_e)%3){
			cout<<0<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}
}