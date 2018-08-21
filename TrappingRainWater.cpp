#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,arr[1000],maxL[1000],maxR[1000],maxh,water;
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>arr[i];
		maxh=INT_MIN;
		maxL[0]=0;
		for(int i=1;i<N;i++){
			maxh=max(maxh,arr[i-1]);
			maxL[i]=maxh;
			if(arr[i]>maxL[i])
				maxL[i]=0;
		}
		maxh=INT_MIN;
		maxR[N-1]=0;
		for(int i=N-2;i>=0;i--){
			maxh=max(maxh,arr[i+1]);
			maxR[i]=maxh;
			if(arr[i]>maxR[i])
				maxR[i]=0;
		}
		water=0;
		for(int i=0;i<N;i++){
			if(min(maxL[i],maxR[i]))
				water+=min(maxL[i],maxR[i])-arr[i];
		}
		cout<<water<<endl;
	}
}