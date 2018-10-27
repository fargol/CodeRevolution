#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int main(){
	ios::sync_with_stdio(true);
	long long int N,M,A[100001],B[100001];
	cin>>N>>M;
	for(long long int i=0;i<N;i++){
		cin>>A[i];
	}
	for(long long int i=0;i<N;i++)
		cin>>B[i];
	long long int high=pow(10,18);
	long long int low=0,mid,min_balloon,curr;
	while(low<high){
		mid=(low+high)>>1;
		min_balloon=0;
		for(long long int i=0;i<N;i++){
			curr=mid/B[i];
			curr=A[i]-curr;
			if(curr>=0)
				min_balloon+=curr;
		}
		if(min_balloon<=M){
			high=mid;
		}
		else{
			low=mid+1;
		}
	}
	cout<<low;
	cout<<endl;
}