#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T;
	string A,B;
	cin>>T;
	int count;
	int Al,Bl;
	while(T--){
		cin>>A>>B;
		set<char> As,Bs;
		Al=A.length();
		Bl=B.length();
		if(Al!=Bl){
			cout<<-1<<endl;
			continue;
		}
		for(int i=0;i<Al;i++)
			As.insert(A[i]);
		for(int i=0;i<Bl;i++)
			Bs.insert(B[i]);
		if(As!=Bs){
			cout<<-1<<endl;
			continue;
		}
		int j=Al-1;
		count=0;
		for(int i=Al-1;i>=0;i--){
			if(A[i]==B[j]){
				j--;
			}
			else{
				count++;
			}
		}
		cout<<count<<endl;
	}
}