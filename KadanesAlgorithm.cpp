#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,max,sum;
	cin>>T;
	while(T--){
		cin>>N;
		vector<int> arr(N);
		sum=0;
		max=INT_MIN;
		for(int &i:arr)
			cin>>i;
		for(int i=0;i<N;i++){
			sum+=arr[i];
			if(max<sum)
				max=sum;
			if(sum<0)
				sum=0;
		}
		cout<<max<<endl;
	}
}