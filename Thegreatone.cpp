#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
#define ll long long
bool is_three_div(ll int N){
	if(N==1){
		return false;
	}
	ll int sqt=sqrt(N),c=0;
	sqt*=sqt;
	if(sqt==N){
		sqt=sqrt(N);
		for(ll int i=2;i<=sqrt(sqt);i++){
			if(sqt%i==0){
				c++;
			}
		}
		if(c==0){
			return true;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(true);
	ll int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		vector<ll int> arr(N);
		vector<string> res;
		for(ll int &i:arr){
			cin>>i;
			// cout<<" i = "<<i<<endl;
			if(is_three_div(i)){
				// cout<<"true\n";
				res.push_back(to_string(i));
			}
		}
		if(res.size()==0){
			cout<<-1<<endl;
			continue;
		}
		sort(res.rbegin(),res.rend());
		for(ll int i=0;i<res.size();i++){
			cout<<res[i];
		}
		cout<<endl;
	}
}