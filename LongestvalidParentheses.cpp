#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int main(){
	ios::sync_with_stdio(true);
	int T,maxl,c;
	cin>>T;
	string S;
	while(T--){
		cin>>S;
		stack<pair<char,int> > brac;
		brac.push(make_pair(')',-1));
		maxl=0;
		for(int i=0;i<S.length();i++){
			//cout<<"i = "<<i<<endl;
			if(S[i]=='('){
				brac.push(make_pair('(',i));
			}
			else{
				if(!brac.empty()&&brac.top().first=='('){
					brac.pop();
					if(!brac.empty()){
						maxl=max(maxl,i-brac.top().second);
					}
				}
				else{
					brac.push(make_pair(')',i));
				}
			}
		}
		cout<<maxl<<endl;
	}
}