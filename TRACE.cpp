#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(false);
	int T,N;
	cin>>T;
	int arr[110][110];
	long long int max,sum;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)
				cin>>arr[i][j];
		}
		max=LLONG_MIN;
		for(int i=1;i<=N;i++){
			for(int j=0;j<N-i+1;j++){
				for(int k=0;k<N-i+1;k++){
					sum=0;
					for(int p=0;p<i;p++)
						sum+=arr[j+p][k+p];
					if(max<sum)
						max=sum;
				}
			}
		}
		cout<<max<<endl;
	}
}