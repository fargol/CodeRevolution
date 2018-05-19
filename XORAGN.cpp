#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(false);
	int T,N;
	cin>>T;
	long long int arr[100001],res;
	while(T--){
		cin>>N;
		res=0;
		//min=INT_MAX;
		for(int i=0;i<N;i++){
			cin>>arr[i];
			arr[i]*=2;
			res^=arr[i];
			//if(min>arr[i])
				//min=arr[i];
		}
		cout<<res<<endl;
	}
}