#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(false);
	int T,n,m;
	cin>>T;
	int count;
	int element;
	long long int val;
	while(T--){
		cin>>n>>m;
		count=0;
		while(n--){
			cin>>element;
			if(element%m==0)
				count++;
		}
		val=pow(2,count)-1;
		cout<<val<<endl;
	}
}