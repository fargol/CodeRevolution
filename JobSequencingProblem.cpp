#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
struct JOB{
	int id;
	int deadline;
	int profit;
};
bool cmp(const JOB a,const JOB b){
	return (a.profit>b.profit);
}
int main(){
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		JOB arr[N];
		for(int i=0;i<N;i++){
			cin>>arr[i].id>>arr[i].deadline>>arr[i].profit;
		}
		sort(arr,arr+N,cmp);
		int count=0,total_profit=0;
		bool slot[N+1];
		memset(slot,false,N*sizeof(slot[0]));
		for(int i=0;i<N;i++){
			for(int j=min(N,arr[i].deadline);j>0;j--){
				if(!slot[j]){
					slot[j]=true;
					count++;
					total_profit+=arr[i].profit;
					break;
				}
			}
		}
		cout<<count<<" "<<total_profit<<endl;
	}
}