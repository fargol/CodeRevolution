#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<long long int, long long int> ii; typedef vector<ii> vii;
long long int CountOfSubarrays(long long int arr[],long long int N,long long int K){
	long long int prod=1,res=0;
	long long int st,ed;
	for(st=0,ed=0;ed<N;ed++){
		prod*=arr[ed];
		while(prod>K)
			prod/=arr[st++];
		if(prod<K)
			res+=(ed-st)+1;
	}
	return res;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<long long int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	long long int N,T,K;
	cin>>T;
	while(T--){
		cin>>N>>K;
		long long int arr[N];
		for(long long int &i:arr)
			cin>>i;
		cout<<CountOfSubarrays(arr,N,K)<<endl;
	}
}