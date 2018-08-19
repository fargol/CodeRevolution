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
		int arr[N];
		for(int &i:arr)
			cin>>i;
		int i;
		for(i=N-1;i>0;i--){
			if(arr[i]>arr[i-1])
				break;
		}
		//cout<<"i = "<<i<<endl;
		if(i==0){
			for(int i=N-1;i>=0;i--)
				cout<<arr[i]<<" ";
		}
		else{
			int min=INT_MAX,id,j;
			for(int j=i;j<N;j++){
				if(min>arr[j]&&arr[j]>arr[i-1]){
					min=arr[j];
					id=j;
				}
			}
			j=id;
			arr[j]=arr[j]^arr[i-1];
			arr[i-1]=arr[j]^arr[i-1];
			arr[j]=arr[j]^arr[i-1];
			for(int j=0;j<i;j++)
				cout<<arr[j]<<" ";
			for(int j=N-1;j>=i;j--)
				cout<<arr[j]<<" ";
		}
		cout<<endl;
	}	
}