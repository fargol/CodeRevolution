#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define MOD 1000000007;
typedef pair<long long int, long long int> ii; typedef vector<ii> vii;
#define push_back pb;
int main(){
	ios::sync_with_stdio(false);
	long long int T,N;
	long long int temp;
	cin>>T;
	long long int arr[100010];//arr2[100010];
	//vector<long long int> util(3);
	while(T--){
		cin>>N;
		for(long long int i=0;i<N;i++){
			cin>>arr[i];
			//arr2[i]=arr1[i];
		}
		if(N>=2){
			if(arr[0]<arr[1])
				arr[0]*=-1;
		if(N>=3){
			for(int i=1;i<N-1;i++){
				if(arr[i-1]>arr[i]&&arr[i]<arr[i+1])
					arr[i]*=-1;
			}
			if(arr[N-1]<arr[N-2])
				arr[N-1]*=-1;
		}
			long long int sum=0;
			for(int i=0;i<N-2;i++){
				sum=arr[i]+arr[i+1]+arr[i+2];
				if(sum<=0){
					if(arr[i]<0){
						if(abs(arr[i])<=arr[i+2])
							arr[i]*=-1;
						else
							arr[i+2]*=-1;
					}
					else
						arr[i+1]*=-1;
				}
			}
		}
		for(long long int i=0;i<N;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
}