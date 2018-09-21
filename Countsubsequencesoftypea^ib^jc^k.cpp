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
	while(T--){
		string S;
		cin>>S;
		int aCount=0,bCount=0,cCount=0;
		for(int i=0;i<S.length();i++){
			if(S[i]=='a'){
				aCount=1+2*aCount;
			}
			else if(S[i]=='b'){
				bCount=aCount+2*bCount;
			}
			else{
				cCount=bCount+2*cCount;
			}
		}
		cout<<cCount<<endl;
	}
}