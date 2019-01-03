#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 1000000007
#define ll long long
int main(){
	ios::sync_with_stdio(true);
	int T;
	cin>>T;
	string S;
	while(T--){
		cin>>S;
		string res="",curs="";
		int maxl=0,currl;
		int i=0;
		curs=S[i];
		i++;
		currl=1;
		while(i<S.length()){
			if(maxl<currl){
				maxl=currl;
				res=curs;
			}
			if((S[i]-S[i-1]==1)||(S[i]=='a'&&S[i-1]=='z')){
				curs+=S[i];
				currl++;
			}
			else{
				currl=1;
				curs=S[i];
			}
			i++;
		}
		if(maxl<currl){
			maxl=currl;
			res=curs;
		}
		cout<<res<<"\n"<<maxl<<endl;
	}
}