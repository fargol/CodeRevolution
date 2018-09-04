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
	int arr[]={1,2,5,10,20,50,100,500,1000};
	while(T--){
		cin>>N;
		int c=0;
		vector<int> deno;
		for(int i=8;i>=0;i--){
		    while(N>=arr[i]){
			    N-=arr[i];
			    deno.push_back(arr[i]);
			    c++;
		    }
		}
		for(int i=0;i<c;i++)
			cout<<deno[i]<<" ";
		cout<<endl;
	}
}