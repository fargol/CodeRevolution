#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,e,c;
	cin>>T;
	int arr[1000];
	while(T--){
		cin>>N;
		unordered_map<int,int> ump;
		for(int i=0;i<N;i++){
			cin>>arr[i];
			ump[arr[i]]=1;
		} 
		int max=1;
		for(int i=0;i<N;i++){
			if(ump.find(arr[i]-1)==ump.end()){
				//cout<<"arr[i] = "<<arr[i]<<" ";
				e=arr[i]+1;
				c=1;
				while(ump.find(e)!=ump.end()){
					e++;
					c++;
				}
				if(max<c)
					max=c;
			}
		}
		//cout<<endl;
		cout<<max<<endl;
	}		
}