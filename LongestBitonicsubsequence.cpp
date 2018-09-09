#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	int arr[1010];
	int LIS[1010];
	int LDS[1010];
	cin>>T;
	int maxDp;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>arr[i];
		}
		LIS[0]=1;
		for(int i=1;i<N;i++){
			LIS[i]=1;
			for(int j=0;j<i;j++){
				if(arr[j]<arr[i]){ //LIS
					if(LIS[i]<LIS[j]+1){
						LIS[i]=LIS[j]+1;
					}
				}
			}
		}
		LDS[N-1]=1;
		for(int i=N-2;i>=0;i--){
			LDS[i]=1;
			for(int j=N-1;j>i;j--){
				if(arr[j]<arr[i]){ //LDS
					if(LDS[i]<LDS[j]+1){
						LDS[i]=LDS[j]+1;
					}
				}
			}
		}
		maxDp=LIS[0]+LDS[0]-1;
		for(int i=1;i<N;i++){
			if(maxDp<LIS[i]+LDS[i]-1)
				maxDp=LIS[i]+LDS[i]-1;
		}
		cout<<maxDp<<endl;
	}
}