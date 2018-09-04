#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,mem,arr[1100];
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>arr[i];
		cin>>mem;
		queue<int> Q;
		unordered_map<int,bool> hm;
		int faults=0;
		for(int i=0;i<N;i++){
			if(hm.find(arr[i])==hm.end()){
				faults++;
				if(Q.size()<mem){
					hm[arr[i]]=true;
					Q.push(arr[i]);
				}
				else{
					hm.erase(Q.front());
					Q.pop();
					hm[arr[i]]=true;
					Q.push(arr[i]);
				}
			}
		}
		cout<<faults<<endl;
	}	
}