#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,m,n,a1[5000],a2[5000],a12[5000];
	cin>>T;
	while(T--){
		cin>>m>>n;
		unordered_map<int,int> hm;
		for(int i=0;i<m;i++)
			cin>>a1[i];
		for(int j=0;j<n;j++){
			cin>>a2[j];
			hm[a2[j]]=0;
		}
		for(int i=0;i<m;i++){
			if(hm.find(a1[i])!=hm.end())
				hm[a1[i]]++;
		}
		int k=0;
		for(int j=0;j<n;j++){
			for(int i=0;i<hm[a2[j]];i++){
				a12[k]=a2[j];
				k++;
			}
		}
		int c=k;
		for(int i=0;i<m;i++){
			if(hm.find(a1[i])==hm.end()){
				a12[k]=a1[i];
				k++;
			}
		}
		sort(a12+c,a12+m);
		for(int i=0;i<m;i++)
			cout<<a12[i]<<" ";
		cout<<endl;
	}	
}