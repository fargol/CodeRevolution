#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 1000000007
#define ll long long
int main(){
	ios::sync_with_stdio(true);
	int T,N,ups,downs;
	cin>>T;
	while(T--){
		cin>>N;
		vector<int> arr(N);
		for(int &i:arr)
			cin>>i;
		ups=downs=0;
		for(int i=1;i<N-1;i++){
			if(arr[i-1]>arr[i]&&arr[i]<arr[i+1]){
				downs++;
			}
			if(arr[i-1]<arr[i]&&arr[i]>arr[i+1]){
				ups++;
			}
		}
		cout<<ups<<" "<<downs<<endl;	
	}
}