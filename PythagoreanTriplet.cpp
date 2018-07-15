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
		for(int &i:arr){
			cin>>i;
			i*=i;
		}
		sort(arr.begin(),arr.end());
		/*for(int &i:arr)
			cout<<i<<" ";
		cout<<endl;*/
		bool flag=false;
		for(int i=N-1;i>=0;i--){
			c=arr[i];
			int j=0,k=i-1;
			while(j<k){
				a=arr[j];
				b=arr[k];
				if(a+b==c){
					flag=true;
					break;
				}
				else if(a+b<c)
					j++;
				else
					k--;
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