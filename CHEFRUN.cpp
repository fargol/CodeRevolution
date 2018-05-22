#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(false);
	int T;
	double X1,X2,X3,V1,V2;
	double d1,d2,t1,t2;
	cin>>T;
	while(T--){
		cin>>X1>>X2>>X3>>V1>>V2;
		d1=X3-X1;
		t1=d1/V1;
		d2=X2-X3;
		t2=d2/V2;
		if(t1<t2)
			cout<<"Chef\n";
		else if(t1==t2)
			cout<<"Draw\n";
		else
			cout<<"Kefa\n";

	}
}