#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main(){
	int T,N,curr,max,flag;
	cin>>T;
	long long int sum=0;
	while(T--){
		cin>>N;
		vector<vector<int> > arr(N,vector<int>(N));
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)
				cin>>arr[i][j];
		}
		curr=INT_MAX;
		sum=flag=0;
		for(int i=N-1;i>=0;i--){
			max=INT_MIN;
			for(int j=0;j<N;j++){
				if(arr[i][j]>max&&arr[i][j]<curr)
					max=arr[i][j];
			}
			if(max==INT_MIN){
				cout<<"-1\n";
				flag=1;
				break;
			}
			sum+=max;
			curr=max;
		}
		if(flag==0)
			cout<<sum<<endl;
	}
}