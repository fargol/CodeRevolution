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
		stack<char> brac;
		brac.push(-1);
		maxl=INT_MIN;
		for(int i=0;i<S.length();i++){
			if(S[i]=='(')
				brac.push(i);
			else{
				brac.pop();
				if(!brac.empty()){
					maxl=max(i-brac.top(),maxl);
				}
				else
					brac.push(i);
			}
		}
		cout<<maxl<<endl;
	}
}