#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T;
	string S;
	string str;
	cin>>T;
	while(T--){
		cin>>S;
		//cout<<S<<endl;
		stringstream check(S);
		stack<string> stk;
		while(getline(check,str,'.'))
			stk.push(str);
		S="";
		while(!stk.empty()){
			S+=stk.top();
			stk.pop();
			if(!stk.empty())
				S+='.';
		}
		cout<<S<<endl;
	}
}