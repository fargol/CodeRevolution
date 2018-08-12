#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,m,len;
	string S;
	cin>>T;
	int LPS[100010];
	int maxLPS;
	while(T--){
		cin>>S;
		m=S.length();
		LPS[0]=0;
		maxLPS=LPS[0];
		len=0; //length of previous longest suffix prefix
		for(int i=1;i<m;){
			if(S[i]==S[len]){
				len++;
				LPS[i]=len;
				i++;
			}
			else{
				if(len!=0)
					len=LPS[len-1];
				else{
					LPS[i]=0;
					i++;
				}
			}
		}
		cout<<LPS[m-1]<<endl;
	}
}