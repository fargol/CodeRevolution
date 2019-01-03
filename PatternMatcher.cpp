#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 1000000007
#define ll long long
bool check(string P,string S){
	if(S.length()%P.length()){
		return false;
	}
	int i=0;
	while(i<S.length()){
		string temp=S.substr(i,P.length());
		if(temp!=P){
			return false;
		}
		i+=P.length();
	}
	return true;
}
int main(){
	ios::sync_with_stdio(true);
	int T;
	string S,P,temp;
	cin>>T;
	while(T--){
		cin>>P>>S;
		cout<<check(P,S)<<endl;
	}
}