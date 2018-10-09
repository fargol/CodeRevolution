#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(false);
	int T,N,max_diff;
	cin>>T;
	while(T--){
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++){
			cin>>arr[i];
		}
		int LMin[N],RMax[N];
		LMin[0]=arr[0];
		for(int i=1;i<N;i++){
			LMin[i]=min(LMin[i-1],arr[i]);
		}
		RMax[N-1]=arr[N-1];
		for(int i=N-2;i>=0;i--){
			RMax[i]=max(RMax[i+1],arr[i]);
		}
		int i=0,j=0;
		max_diff=INT_MIN;
		while(i<N&&j<N){
			if(LMin[i]<RMax[j]){
				max_diff=max(max_diff,j-i);
				j++;
			}
			else
				i++;
		}
		cout<<max_diff<<endl;
	}
}