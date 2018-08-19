#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,l;
	string S,text;
	cin>>T;
	while(T--){
		cin>>S;
		l=S.length();
		unordered_map<string,bool> hm;
		for(int i=0;i<l;i++){
			for(int j=0;j<=l;j++){
				if(i-j>=0&&i+j<l){
					if(S[i-j]==S[i+j]){
						text=S.substr(i-j,2*j+1);
						if(hm.find(text)==hm.end()){
							//cout<<"1:"<<text<<endl;
							hm[text]=true;
						}
					}
					else
						break;
				}
				else
					break;
			}
		}
		for(int i=0;i<l-1;i++){
			if(S[i]==S[i+1]){
				for(int j=0;j<=l;j++){
					if(i-j>=0&&i+1+j<l){
						if(S[i-j]==S[i+1+j]){
							text=S.substr(i-j,2*j+2);
							if(hm.find(text)==hm.end()){
								//cout<<"2:"<<text<<endl;
								hm[text]=true;
							}
						}
						else
							break;
					}
					else
						break;
				}
			}
		}
		cout<<hm.size()<<endl;
	}	
}