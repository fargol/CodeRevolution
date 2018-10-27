#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
int main(){
	ios::sync_with_stdio(true);
	int T,n,m;
	cin>>T;
	while(T--){
		cin>>n>>m;
		int matrix[n][m],i,j;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				cin>>matrix[i][j];
			}
		}
		int max1,row;
		int idx=m;
		for(j=0;j<m;j++){
			if(matrix[0][j]==1)
				break;
		}
		idx=j;
		max1=m-idx;
		row=0;
		//cout<<"i = "<<0<<" :: idx = "<<idx<<endl;
		for(i=1;i<n;i++){
			if(matrix[i][idx]==1){
				for(j=idx-1;j>=0;j--){
					if(matrix[i][j]==0){
						break;
					}
				}
				idx=j+1;
				//cout<<"i = "<<i<<" :: idx = "<<idx<<endl;
				if(max1<m-idx){
					max1=m-idx;
					row=i;
				}
			}
		}
		cout<<row<<endl;
	}
}