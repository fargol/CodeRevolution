#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		int arr[N];
		for(int &i:arr)
			cin>>i;
		int max_diff=0;
		int min_ele=arr[0];
		for(int i=1;i<N;i++){
			if(max_diff<arr[i]-min_ele)
				max_diff=arr[i]-min_ele;
			if(min_ele>arr[i])
				min_ele=arr[i];
		}
		cout<<max_diff<<endl;
	}
}