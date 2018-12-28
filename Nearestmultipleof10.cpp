#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 1000000007
#define ll long long
int main(){
	ios::sync_with_stdio(true);
	int T;
	string N;
	cin>>T;
	while(T--){
		cin>>N;
		if(N[N.length()-1]-'0'<=5){
			N=N.substr(0,N.length()-1);
			N+='0';
		}
		else{
			stack<char> st;
			st.push('0');
			int j=N.length()-2;
			bool CF=true;
			while(j>=0){
				if(CF){
					if(N[j]=='9'){
						st.push('0');
						CF=true;
					}
					else{
						st.push(N[j]+1);
						CF=false;
					}
				}
				else{
					st.push(N[j]);
				}
				j--;
			}
			if(CF){
				st.push('1');
			}
			N="";
			while(!st.empty()){
				N+=st.top();
				st.pop();
			}
		}
		cout<<N<<endl;
	}
}