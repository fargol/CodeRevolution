#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		int arr[N];
		for(int &i:arr)
			cin>>i;
		int prod=1,max_prod=1,neg_prod=1;
		for(int i=0;i<N;i++){
			if(arr[i]>0){
				prod*=arr[i];
				neg_prod=min(neg_prod*arr[i],1);
			}
			else if(arr[i]==0){
				prod=1;
				neg_prod=1;
			}
			else{
				int temp=prod;
				prod=max(neg_prod*arr[i],1);
				neg_prod=temp*arr[i];
			}
			if(max_prod<prod)
				max_prod=prod;
		}
		cout<<max_prod<<endl;
	}
}