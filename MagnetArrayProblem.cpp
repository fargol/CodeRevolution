#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
double ls(int idx,int arr[],double x){
	double res=0.0;
	for(int i=0;i<=idx;i++){
		res+=1.0/(x-arr[i]);
	}
	return res;
}
double rs(int idx,int arr[],double x,int N){
	double res=0.0;
	for(int i=idx;i<N;i++){
		res+=1.0/(arr[i]-x);
	}
	return res;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,arr[5000];
	double l,h,mid,r1,r2;
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>arr[i];
		for(int i=0;i<N-1;i++){
			l=arr[i];
			h=arr[i+1];
			while(l<=h){
				//cout<<"here\n";
				mid=(l+h)/2.0;
				//cout<<"mid = "<<mid<<endl;
				r1=ls(i,arr,mid);
				r2=rs(i+1,arr,mid,N);
				if(abs(r1-r2)<=0.0001)
					break;
				if(r1>r2)
					l=mid;
				else if(r2>r1)
					h=mid;
			}
			printf("%.2lf ",mid);
		}
		cout<<endl;
	}
}