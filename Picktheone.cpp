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
		if(arr[0]==1){
			cout<<-1<<endl;
		}
		else{
			int low=0,high=N,mid;
			while(low<=high){
				mid=(low+high)>>1;
				if(arr[mid]==0){
					if(mid==N-1){
						cout<<mid<<endl;
						break;
					}
					else{
						if(arr[mid+1]==1){
							cout<<mid<<endl;
							break;
						}
						else{
							low=mid+1;
						}
					}
				}
				else{
					if(arr[mid-1]==0){
						cout<<mid-1<<endl;
						break;
					}
					else{
						high=mid-1;
					}
				}
			}
		}
	}
}