#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(false);
	int T,N,K,motl,toml;
	cin>>T;
	vector<int> mot(10001),tom(10001);
	long long int motu,tomu;
	while(T--){
		cin>>N>>K;
		motu=tomu=0;
		if(N&1){
			motl=N/2+1;
			toml=N/2;
		}
		else{
			motl=toml=N/2;
		}
		int j=0,k=0;
		for(int i=0;i<N;i++){
			if(i&1){
				cin>>tom[j];
				tomu+=tom[j];
				j++;
			}
			else{
				cin>>mot[k];
				motu+=mot[k];
				k++;
			}
		}
			sort(mot.begin(),mot.begin()+motl);
			sort(tom.begin(),tom.begin()+toml);
			int i=0;
			while(motu>=tomu&&K>0&&i<toml){
				tomu-=tom[i];
				tomu+=mot[motl-i-1];
				motu-=mot[motl-i-1];
				motu+=tom[i];
				i++;
				K--;
			}
		if(tomu>motu){
			cout<<"YES"<<endl;
			continue;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}