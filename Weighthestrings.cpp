#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 1000000007
#define ll long long
int main(){
	ios::sync_with_stdio(true);
	int T;
	cin>>T;
	string X,Y;
	while(T--){
		cin>>X>>Y;
		ll int w1=0,w2=0;
		for(int i=0;i<X.length();i++){
			w1+=X[i]-'\0';
		}
		for(int i=0;i<Y.length();i++){
			w2+=Y[i]-'\0';
		}
		if(w1>w2){
			cout<<X<<endl;
		}
		else if(w1==w2){
			cout<<"equal"<<endl;
		}
		else{
			cout<<Y<<endl;
		}
	}
}