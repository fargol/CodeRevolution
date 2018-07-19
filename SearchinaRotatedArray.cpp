#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int b_s(vector<int> &arr,int low,int high,int K){
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		if(arr[mid]==K)
			return mid;
		else if(arr[mid]>K)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,K,idx,pivot,low,high,mid;
	bool flag;
	vector<int> arr(100005);
	cin>>T;
	while(T--){
		cin>>N;
		flag=false;
		cin>>arr[0];
		for(int i=1;i<N;i++){
			cin>>arr[i];
			if(arr[i-1]>arr[i])
				pivot=i-1;
		}
		cin>>K;
		if(K>=arr[0]){
			cout<<b_s(arr,0,pivot,K)<<endl;
		}
		else{
			cout<<b_s(arr,pivot+1,N-1,K)<<endl;
		}
	}
}