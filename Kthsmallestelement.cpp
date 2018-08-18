#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
inline void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
int ithOrderStats(int *arr,int s,int e,int k){
	if(s==e)
		return arr[s];
	int size=e-s+1;
	int id=rand()%size+s;
	//cout<<" id = "<<id<<endl;
	swap(arr[id],arr[e]);
	int i=s;
	for(int j=s;j<e;j++){
		if(arr[j]<=arr[e]){
			swap(arr[j],arr[i]);
			i++;
		}
	}
	swap(arr[i],arr[e]);
	/*cout<<"\narr = \n";
	for(int i=s;i<=e;i++)
		cout<<arr[i]<<" ";
	cout<<endl;*/
	int pos=i-s;
	if(pos==k-1)
		return arr[pos];
	else if(pos<k){
		return ithOrderStats(arr,i+1,e,k-i-1);
	}
	else
		return ithOrderStats(arr,s,i-1,k);
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	srand(time(NULL));
	ios::sync_with_stdio(true);
	int T,N,K,res;
	cin>>T;
	while(T--){
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
			cin>>arr[i];
		/*cout<<"\narr = \n";
		for(int i=0;i<N;i++)
			cout<<arr[i]<<" ";
		cout<<endl;*/
		cin>>K;
		res=ithOrderStats(arr,0,N-1,K);
		cout<<res<<endl;
	}
}