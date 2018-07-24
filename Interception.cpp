#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	vector<int> P(100);
	vector<int> coeff(100);
	for(int i=1;i<=T;i++){
		printf("Case #%d: ",i);
		cin>>N;
		for(int j=N;j>=0;j--)
			cin>>P[j];
		for(int j=0;j<N;j++)
			coeff[j]=P[j]+j+1;
		coeff[N]=P[N];
		bool flag=false;
		int j;
		for(j=N;j>=0;j--){
			if(coeff[j]==0)
				break;
			if(coeff[j]<0)
				flag=true;
		}
		if(flag||j==N-1){
			cout<<0<<endl;
		}
		else{
			printf("1\n%.1f\n",0.0);
		}
	}
}