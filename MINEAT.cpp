#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int main(){
	ios::sync_with_stdio(false);
	int T;
	int N,H,K;
	long long int sum,lb,ub,steps,curr,rate,min;
	cin>>T;
	while(T--){
		cin>>N>>H;
		vector<int> A(N);
		sum=0;
		for(int i=0;i<N;i++){
			cin>>A[i];
			sum+=A[i];
		}
		lb=ceil(sum*1.0/H);
		//cout<<"lb::"<<lb<<endl;
		sort(A.begin(),A.end());
		ub=A[N-1];
		if(N==H){
			cout<<ub<<endl;
		}
		else{
			//for(long long int i=lb;i<=ub;i++){
			min=LLONG_MAX;
			long long int i;
			while(lb<=ub){
				steps=0;
				//rate=i;
				i=(lb+ub)/2;
				for(int j=N-1;j>=0;j--){
					curr=ceil(A[j]*1.0/i);
					//cout<<"curr::"<<curr<<endl;
					if(curr>1){
						steps+=curr;
					}
					else{
						steps+=j+1;
						//rate=i;
						break;
					}
				}
				//cout<<"steps::"<<steps<<endl;
				if(steps<=H){
					if(min>i)
						min=i;
					ub=i-1;
					//cout<<i<<endl;
					//break;
				}
				else
					lb=i+1;
			}
			cout<<min<<endl;
		}
	}
}