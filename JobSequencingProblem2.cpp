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
class DisjointSet{
private:
	int *parent;
public:
	DisjointSet(int N){
		parent=new int[N+1];
		for(int i=0;i<N+1;i++)
			parent[i]=i;
	}
	int find(int N){
		if(N==parent[N])
			return N;
		return parent[N]=find(parent[N]);
	}
	void merge(int a,int b){
		parent[b]=a;
	}
};
int main(){
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		JOB arr[N];
		int max_deadline=INT_MIN;
		for(int i=0;i<N;i++){
			cin>>arr[i].id>>arr[i].deadline>>arr[i].profit;
			max_deadline=max(max_deadline,arr[i].deadline);
		}
		sort(arr,arr+N,cmp);
		int count=0,total_profit=0;
		DisjointSet ds(max_deadline);
		for(int i=0;i<N;i++){
			int avail_slot=ds.find(arr[i].deadline);
			if(avail_slot>0){
				count++;
				total_profit+=arr[i].profit;
				ds.merge(ds.find(avail_slot-1),avail_slot);
			}
		}
		cout<<count<<" "<<total_profit<<endl;
	}
}