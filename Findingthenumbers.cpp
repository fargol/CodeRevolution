#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int main(){
	ios::sync_with_stdio(false);
	int T,N,l;
	cin>>T;
	vector<int> util(2);
	vector<int> arr(200010);
	while(T--){
		cin>>N;
		l=2*N+2;
		int k=0;
		for(int i=0;i<l;i++)
			cin>>arr[i];
		//sort(arr.begin(),arr.begin()+l);
		if(arr[l-2]<arr[l-1]){
			cout<<arr[l-2]<<" "<<arr[l-1]<<endl;
		}
		else
			cout<<arr[l-1]<<" "<<arr[l-2]<<endl;
		//cout<<endl;
	}
}