#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
inline int bs(vector<int> &S,vector<long long int> &sum,int idx,int N,string text){
	//cout<<"inside bs\n";
	int mid,low,high,min,max;
	long long int diff;
	if(text=="left"){
		low=0;
		high=idx-1;
		min=INT_MAX;
		if(low==idx)
			return -1;
		while(low<=high){
			mid=(low+high)/2;
			diff=sum[idx]-S[idx]-sum[mid];
			if(diff<=S[idx]){
				if(min>mid)
					min=mid;
				high=mid-1;
			}
			else
			low=mid+1;
		}
		//cout<<"hereL\n";
		return min;
	}
	else{
		low=idx+1;
		high=N-1;
		max=INT_MIN;
		if(high==idx)
			return -1;
		while(low<=high){
			mid=(low+high)/2;
			diff=sum[mid]-S[mid]-sum[idx];
			if(diff<=S[idx]){
				if(max<mid)
					max=mid;
				low=mid+1;
			}
			else
			high=mid-1;
		}
		//cout<<"hereR\n";
		return max;
	}
}
inline void increment(vector<long long int> &svotes,vector<long long int> &votes,int lidx,int ridx,int N){
	svotes[lidx]+=1;
	if(ridx+1<N)
		svotes[ridx+1]-=1;
}
int main(){
	ios::sync_with_stdio(false);
	int T,lidx,ridx;
	int N;
	long long int diff;
	cin>>T;
	while(T--){
		cin>>N;
		vector<int> S(N);
		vector<long long int> sum(N);
		vector<long long int> votes(N,0);
		vector<long long int> svotes(N,0);
		//cout<<"taking inputs\n";
		for(int i=0;i<N;i++){
			cin>>S[i];
			if(i==0)
				sum[i]=S[i];
			else
				sum[i]=S[i]+sum[i-1];
		}
		//cout<<"here\n";
		for(int i=0;i<N;i++){
			lidx=bs(S,sum,i,N,"left");
			//cout<<"lidx::"<<lidx<<endl;
			ridx=bs(S,sum,i,N,"right");
			//cout<<"ridx::"<<ridx<<endl;
			if(lidx>-1)
				increment(svotes,votes,lidx,i-1,N);
			if(ridx>-1)
				increment(svotes,votes,i+1,ridx,N);
		}
		votes[0]=svotes[0];
		cout<<votes[0]<<" ";
		for(int i=1;i<N;i++){
			svotes[i]+=svotes[i-1];
			votes[i]+=svotes[i];
			cout<<votes[i]<<" ";
		}
		cout<<endl;
	}
}