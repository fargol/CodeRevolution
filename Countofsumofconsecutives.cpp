#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,c;
	cin>>T;
	double a,ia;
	while(T--){
		cin>>N;
		c=0;
		for(int l=1;l*(l+1)<2*N;l++){
			a=2.0*N-l*(l+1);
			a/=(2.0*(l+1));
			//cout<<"\nl = "<<l<<endl;
			//cout<<"a = "<<a<<endl;
			ia=floor(a);
			//cout<<"ia = "<<ia<<endl;
			if((a-ia)<=0.000001)
				c++;
		}
		cout<<c<<endl;	
	}	
}