#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,a,b,c;
	cin>>T;
	while(T--){
		cin>>N;
		vector<int> arr(N);
		for(int &i:arr)
			cin>>i;
		sort(arr.begin(),arr.end());
		bool flag=false;
		for(int i=0;i<N-2;i++){
			for(int j=i+1;j<N-1;j++){
				for(int k=j+1;k<N;k++){
					a=pow(arr[i],2);
					b=pow(arr[j],2);
					c=pow(arr[k],2);
					if(a+b==c){
						flag=true;
						break;
					}
				}
				if(flag)
					break;
			}
			if(flag)
				break;
		}
		if(flag)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}