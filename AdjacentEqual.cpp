#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 1000000007
#define ll long long
int main(){
	ios::sync_with_stdio(true);
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++){
			cin>>arr[i];
		}
		int count=0;
		for(int i=1;i<N;i++){
			if(arr[i]==arr[i-1]){
				count++;
			}
		}
		cout<<count<<endl;
	}
}