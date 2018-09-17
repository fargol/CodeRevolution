#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		int A[N];
		for(int &i:A)
			cin>>i;
		int low=0,mid=0,high=N-1;
		while(mid<=high){
			if(A[mid]==0){
				swap(A[low],A[mid]);
				mid++;
				low++;
			}
			else if(A[mid]==1){
				mid++;
			}
			else{
				swap(A[mid],A[high]);
				high--;
			}
		}
		for(int &i:A)
			cout<<i<<" ";
		cout<<endl;
	}
}