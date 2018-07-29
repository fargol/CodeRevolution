#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	vector<int> entry(100010);
	vector<int> exit(100010);
	int count,maxcount,time;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>entry[i];
		for(int i=0;i<N;i++)
			cin>>exit[i];
		sort(entry.begin(),entry.begin()+N);
		sort(exit.begin(),exit.begin()+N);
		maxcount=INT_MIN;
		time;
		count=0;
		int i=0,j=0;
		while(i<N&&j<N){
			if(entry[i]<=exit[j]){
				count++;
				if(maxcount<count){
					maxcount=count;
					time=entry[i];
				}
				i++;
			}
			else{
				count--;
				if(maxcount<count){
					maxcount=count;
					time=exit[j];
				}
				j++;
			}
		}
		cout<<maxcount<<" "<<time<<endl;
	}
}