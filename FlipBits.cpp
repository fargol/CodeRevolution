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
		int c1=0;
		int arr2[N];
		for(int i=0;i<N;i++){
			cin>>arr[i];
			if(arr[i]){
				c1++;
				arr2[i]=-1;
			}
			else{
				arr2[i]=1;
			}
		}
		int maxS=INT_MIN,sum=0;
		for(int i=0;i<N;i++){
			sum+=arr2[i];
			maxS=max(maxS,sum);
			if(sum<0)
				sum=0;
		}
		if(maxS>=0){
			cout<<(maxS+c1)<<endl;
		}
		else
			cout<<c1<<endl;
	}
}