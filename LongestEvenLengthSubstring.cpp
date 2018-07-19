#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,sum1,sum2,max;
	string S;
	vector<int> csum(110);
	cin>>T;
	while(T--){
		cin>>S;
		max=0;
		N=S.length();
		csum[0]=0;
		for(int i=1;i<=N;i++)
			csum[i]=csum[i-1]+S[i-1]-'0';
		for(int i=2;i<=N;i+=2){
			for(int j=1;j<=N-i+1;j++){
				sum1=csum[j+i/2-1]-csum[j-1];
				sum2=csum[j+i-1]-csum[j+i/2-1];
				if(sum1==sum2){
					if(max<i)
						max=i;
				}
			}
		}
		cout<<max<<endl;
	}
}