#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,n,m;
	cin>>T;
	int max;
	int maxf,sum;
	vector<vector<int> > arr(50,vector<int>(50));
	while(T--){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
			}
		}
		maxf=sum=0;
		for(int j=0;j<m;j++){
			sum+=arr[0][j];
			if(maxf<sum)
				maxf=sum;
			if(arr[0][j]==0)
				sum=0;
		}
		max=0;
		if(max<maxf)
			max=maxf;
		cout<<"arr[0] = "<<maxf<<endl;
		for(int i=1;i<n;i++){
			maxf=sum=0;
			for(int j=0;j<m;j++){
				if(arr[i][j]==1)
					arr[i][j]+=arr[i-1][j];
			}
			for(int j=0;j<m;j++){
				sum+=arr[i][j];
				if(maxf<sum)
					maxf=sum;
				if(arr[i][j]==0)
					sum=0;
			}
			cout<<"arr["<<i<<"] = "<<maxf<<endl;
			if(max<maxf)
				max=maxf;
		}
		cout<<max<<endl;
	}
}