#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
void check(int arr[],int L,int N){
	int i=0,j=0;
	while(i<L&&j<L){
		if(arr[j]-arr[i]==N){
			cout<<1<<endl;
			return;
		}
		else if(arr[j]-arr[i]<N){
			j++;
		}
		else
			i++;
	}
	cout<<-1<<endl;
	return;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,L;
	cin>>T;
	while(T--){
		cin>>L>>N;
		int arr[L];
		for(int &i:arr)
			cin>>i;
		sort(arr,arr+L);
		check(arr,L,N);
	}
}