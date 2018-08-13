#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,R,C;
	cin>>T;
	while(T--){
		cin>>R>>C;
		int matrix[R][C];
		int matSum[R][C];
		int temp[R];
		for(int i=0;i<R;i++){
			cin>>matrix[i][0];
			matSum[i][0]=matrix[i][0];
			for(int j=1;j<C;j++){
				cin>>matrix[i][j];
				matSum[i][j]=matSum[i][j-1]+matrix[i][j];
			}
		}
		/*cout<<"matrix = \n";
		for(int i=0;i<R;i++){
			//matSum[i][0]=0;
			for(int j=0;j<C;j++){
				cout<<matrix[i][j]<<" ";
				//matSum[i][j]=matrix[i][j];
			}
			cout<<endl;
		}
		cout<<"matSum = \n";
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++)
				cout<<matSum[i][j]<<" ";
			cout<<endl;
		}*/
		int maxSumRec=INT_MIN;
		for(int i=0;i<C;i++){
			for(int j=i;j<C;j++){
				for(int k=0;k<R;k++)
					temp[k]=matSum[k][j]-matSum[k][i]+matrix[k][i];
				int max_till=INT_MIN,sum=0;
				for(int k=0;k<R;k++){
					sum+=temp[k];
					if(max_till<sum)
						max_till=sum;
					if(sum<0)
						sum=0;
				}
				//cout<<"max col sum = "<<max_till<<endl;
				if(maxSumRec<max_till)
					maxSumRec=max_till;
			}
		}
		cout<<maxSumRec<<endl;
	}	
}