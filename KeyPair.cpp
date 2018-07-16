#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
inline string check(vector<int> &arr,int X,int N){
	sort(arr.begin(),arr.end());
	int i=0,j=N-1;
	int sum;
	while(i<j){
		sum=arr[i]+arr[j];
		if(sum==X)
			return "Yes";
		else if(sum<X)
			i++;
		else
			j--;
	}
	return "No";
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,X;
	cin>>T;
	while(T--){
		cin>>N>>X;
		vector<int> arr(N);
		for(int &i:arr)
			cin>>i;
		cout<<check(arr,X,N)<<endl;
	}
}