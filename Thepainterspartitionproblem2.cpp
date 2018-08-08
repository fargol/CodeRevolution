#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
inline int numberOfPainters(int A[],int n,int maxLen){
	int total=0,numPainters=1;
	for(int i=0;i<n;i++){
		total+=A[i];
		if(total>maxLen){
			total=A[i];
			numPainters++;
		}
	}
	return numPainters;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,n,k,max,high,low,mid,nk;
	cin>>T;
	int dp[100][100];
	int A[100];
	int sum[100];
	while(T--){
		cin>>k>>n;
		cin>>A[0];
		sum[0]=A[0];
		max=A[0];
		for(int i=1;i<n;i++){
			cin>>A[i];
			sum[i]=sum[i-1]+A[i];
			if(max<A[i])
				max=A[i];
		}	
		high=sum[n-1];
		low=max;
		while(low<high){
			mid=(low+high)/2;
			nk=numberOfPainters(A,n,mid);
			if(nk<=k)
				high=mid;
			else
				low=mid+1;
		}
		cout<<low<<endl;
	}
}