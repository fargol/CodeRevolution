#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 1000000007
#define ll long long
int main(){
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		vector<int> A(N);
		for(int &i:A){
			cin>>i;
		}
		int leftspan[N];
		int rightspan[N];
		stack<int> s;
		for(int i=0;i<N;i++){
			while(!s.empty()&&A[s.top()]>=A[i])
				s.pop();
			if(s.empty()){
				leftspan[i]=0;
			}
			else{
				leftspan[i]=s.top()+1;
			}
			s.push(i);
		}
		while(!s.empty())
			s.pop();
		for(int i=N-1;i>=0;i--){
			while(!s.empty()&&A[s.top()]>=A[i])
				s.pop();
			if(s.empty()){
				rightspan[i]=N-1;
			}
			else{
				rightspan[i]=s.top()-1;
			}
			s.push(i);
		}
		vector<pair<int,int> > arr(N);
		for(int i=0;i<N;i++){
			arr[i].first=A[i];
			arr[i].second=i;
		}
		sort(arr.rbegin(),arr.rend());
		vector<int> res(N);
		int j=0;
		for(int i=0;i<N;i++){
			int span=rightspan[arr[i].second]-leftspan[arr[i].second];
			for(;j<=span;j++){
				res[j]=arr[i].first;
			}
		}
		for(int i=0;i<N;i++){
			cout<<res[i]<<" ";
		}
		cout<<endl;
	}
}