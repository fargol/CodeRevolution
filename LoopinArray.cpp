#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 1000000007
#define ll long long
int main(){
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		vector<int> arr(N);
		for(int &i:arr)
			cin>>i;
		int i=0;
		bool flag=false;
		while(0<=i&&i<N){
			if(arr[i]<0){
				cout<<1<<endl;
				flag=true;
				break;
			}
			else{
				int j=arr[i];
				arr[i]=0-arr[i]-1;
				i=j;
			}
		}
		if(!flag){
			cout<<0<<endl;
		}
	}
}