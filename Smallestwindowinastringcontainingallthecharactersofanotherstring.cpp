#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
const int no_of_chars=256;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T;
	string N,X;
	cin>>T;
	while(T--){
		cin>>N>>X;
		vector<int> NN(no_of_chars,0);
		vector<int> XX(no_of_chars,0);
		for(int i=0;i<X.length();i++){
			XX[X[i]]++;
		}
		if(N.length()<X.length()){
			cout<<-1<<endl;
		}
		else{
			int count=0,j=0,start_idx=-1,min_l=INT_MAX;
			for(int i=0;i<N.length();i++){
				NN[N[i]]++;
				if(NN[N[i]]>0&&NN[N[i]]<=XX[N[i]])
					count++;
				if(count==X.length()){
					while(XX[N[j]]<NN[N[j]]||XX[N[j]]==0){
						if(XX[N[j]]<NN[N[j]])
							NN[N[j]]--;
						j++;
					}
					if(min_l>i-j+1){
						min_l=i-j+1;
						start_idx=j;
					}
				}
			}
			if(start_idx==-1){
				cout<<-1<<endl;
			}
			else{
				cout<<N.substr(start_idx,min_l)<<endl;
			}
		}
	}
}