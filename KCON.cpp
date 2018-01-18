#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void maxsubsum(vector<int> &arr,long long int &sum,int &id1,int &id2){
	long long int maxsofar=arr[0];
	long long int curr=arr[0];
	int ti=0;
	id1=id2=0;
	for(int i=1;i<arr.size();i++){
		curr+=arr[i];
		if(maxsofar<curr){
			maxsofar=curr;
			id1=ti;
			id2=i;
		}
		if(curr<0){
			curr=0;
			ti=i;
		}
	}
	sum=maxsofar;
}

int main(){
	int T,N,K,id1,id2;
	long long int sum,arrsum;
	cin>>T;
	while(T--){
		cin>>N>>K;
		if(K==1){
			vector<int> arr(N);
			for(int &i:arr)
				cin>>i;
			maxsubsum(arr,sum,id1,id2);
			cout<<sum<<endl;
		}
		else if(K==2){
			vector<int> arr(2*N);
			for(int i=0;i<N;i++){
				cin>>arr[i];
				arr[N+i]=arr[i];
			}
			maxsubsum(arr,sum,id1,id2);
			cout<<sum<<endl;
		}
		else{
			arrsum=0;
			vector<int> arr(3*N);
			for(int i=0;i<N;i++){
				cin>>arr[i];
				arrsum+=arr[i];
				arr[N+i]=arr[i];
				arr[2*N+i]=arr[i];
			}
			maxsubsum(arr,sum,id1,id2);
			if(id1>=0&&id2>2*N-1)
				sum=arrsum*(K-2)+sum-arrsum;
			cout<<sum<<endl;
		}
	}
}