#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,arr[9999];
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>arr[i];
		sort(arr,arr+N);
		int i=0,j=N-1,sum=INT_MAX,e1,e2;
		while(i<j){
			if(sum>abs(arr[i]+arr[j])){
				sum=abs(arr[i]+arr[j]);
				e1=arr[i];
				e2=arr[j];
			}
			if(arr[i]+arr[j]>0)
				j--;
			else if(arr[i]+arr[j]<0)
				i++;
			else
				break;
		}
		cout<<e1<<" "<<e2<<endl;
	}
}