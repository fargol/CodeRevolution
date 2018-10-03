#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<long long int, long long int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<long long int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	long long int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		long long int arr[N];
		for(long long int &i:arr)
			cin>>i;
		long long int right[N];
		long long int sum=0;
		long long int i=0,j=0;
		while(i<N){
			j=i;
			sum+=arr[j];
			j++;
			while(j<N&&arr[j]<arr[j-1]){
				sum+=arr[j];
				j++;
			}
			right[i]=sum;
			sum-=arr[i];
			i++;
			while(sum>0){
				right[i]=sum;
				sum-=arr[i];
				i++;
			}
		}
		long long int left[N];
		sum=0;
		i=N-1;
		while(i>=0){
			j=i;
			sum+=arr[j];
			j--;
			while(j>=0&&arr[j]<arr[j+1]){
				sum+=arr[j];
				j--;
			}
			left[i]=sum;
			sum-=arr[i];
			i--;
			while(sum>0){
				left[i]=sum;
				sum-=arr[i];
				i--;
			}
		}
		cout<<"right=\n";
		for(int i=0;i<N;i++)
			cout<<right[i]<<" ";
		cout<<endl;
		cout<<"left=\n";
		for(int i=0;i<N;i++)
			cout<<left[i]<<" ";
		cout<<endl;
		long long int maxSum=INT_MIN;
		for(i=0;i<N;i++){
			maxSum=max(maxSum,left[i]+right[i]-arr[i]);
		}
		cout<<maxSum<<endl;
	}
}