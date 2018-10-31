#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
//#define M 1000000007;
#define ll long long
inline bool stud(int M,int P[],int N,int curr_min){
	int p_sum=0;
	int cnt=1;
	for(int i=0;i<N;i++){
		if(P[i]>curr_min)
			return false;
		else if(p_sum+P[i]>curr_min){
			cnt++;
			p_sum=P[i];
		}
		else{
			p_sum+=P[i];
		}
		if(cnt>M)
			return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(true);
	int T,N,M,p_sum;
	cin>>T;
	while(T--){
		cin>>N;
		int P[N];
		p_sum=0;
		for(int &i:P){
			cin>>i;
			p_sum+=i;
		}
		cin>>M;
		if(M>N){
			cout<<-1<<endl;
			continue;
		}
		//cout<<"total pages = "<<p_sum<<endl;
		int high=p_sum,low=0,mid,cnt=INT_MAX;
		while(low<=high){
			mid=(low+high)>>1;
			if(stud(M,P,N,mid)){
				cnt=min(cnt,mid);
				high=mid-1;
			}
			else{
				low=mid+1;
			}
		}
		cout<<cnt<<endl;
	}
}