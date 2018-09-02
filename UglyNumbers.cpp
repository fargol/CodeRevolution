#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	long long int T,N,ugly[5400],u2,u3,u5,i2,i3,i5;
	cin>>T;
	ugly[0]=1;
	u2=2;
	u3=3;
	u5=5;
	i2=i3=i5=0;
	for(int i=1;i<=5302;i++){
		ugly[i]=min(u2,min(u3,u5));
		if(ugly[i]==u2){
			i2++;
			u2=ugly[i2]*2;
		}
		if(ugly[i]==u3){
			i3++;
			u3=ugly[i3]*3;
		}
		if(ugly[i]==u5){
			i5++;
			u5=ugly[i5]*5;
		}
	}
	sort(ugly,ugly+5303);
	while(T--){
		cin>>N;
		cout<<ugly[N-1]<<endl;
	}
}