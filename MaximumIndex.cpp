#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(false);
	int T,N,i,j,k,maxdiff,temp;
	cin>>T;
	int arr[1000];
	char sign[999];
	while(T--){
		cin>>N;
		cin>>arr[0];
		maxdiff=0;
		for(i=1;i<N;i++){
			cin>>arr[i];
			/*if(arr[i]>arr[i-1])
				sign[i-1]='l';
			else if(arr[i]<arr[i-1])
				sign[i-1]='g';
			else
				sign[i-1]='e';*/
		}
		for(i=0;i<N;i++){
			for(j=N-1;j>=i;j--){
				temp=j-i;
				if(arr[j]>=arr[i]&&maxdiff<temp)
					maxdiff=temp;
			}
		}
		cout<<maxdiff<<endl;
	}
}