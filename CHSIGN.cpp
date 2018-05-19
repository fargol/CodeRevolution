#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define MOD 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
#define push_back pb;
int main(){
	ios::sync_with_stdio(false);
	int T,N;
	cin>>T;
	int arr[100010];
	long long int PP[100010];
	long long int NP[100010];
	long long int PN[100010];
	while(T--){
		cin>>N;
		for(int i=1;i<=N;i++)
			cin>>arr[i];
		PP[2]=arr[1]+arr[2];
		PP[1]=arr[1];
		long long int sum;
		if(arr[1]>arr[2]){
			NP[2]=LLONG_MAX;
			NP[1]=arr[1];
			PN[2]=arr[1]-arr[2];
			PN[1]=LLONG_MAX;
		}
		else if(arr[1]==arr[2]){
			NP[2]=PN[2]=LLONG_MAX;
			NP[1]=arr[1];
		}
		else{
			NP[2]=arr[2]-arr[1];
			NP[1]=arr[1];
			PN[2]=LLONG_MAX;
			PN[1]=LLONG_MAX;
		}
		for(int i=3;i<=N;i++){
			PP[i]=min(NP[i-1],PP[i-1])+arr[i];
			if(arr[i]>arr[i-1])
				NP[i]=PN[i-1]+arr[i];
			else
				NP[i]=LLONG_MAX;
			sum=arr[i]+arr[i-2];
			if(arr[i-1]>sum)
				PN[i]=min(NP[i-1],PP[i-1])-arr[i];
			else if(sum>arr[i-1]&&arr[i-1]>arr[i])
				PN[i]=PP[i-1]-arr[i];
			else
				PN[i]=LLONG_MAX;
		}
		cout<<"MINSUM = "<<min(PP[N],min(PN[N],NP[N]))<<endl;
		for(int i=1;i<j;i++){
			if(PP[i]<=PN[i]&&PP[i]<=NP[i])
			else if(PN[i]<=PP[i]&&PN[i]<=NP[i])
			else
		}
		cout<<endl;
	}
}