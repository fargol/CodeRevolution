#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,high,low,start,end,maxlen;
	string S;
	cin>>T;
	while(T--){
		cin>>S;
		maxlen=INT_MIN;
		for(int i=0;i<S.length();i++){
			high=i;low=i;
			while(low>0&&high<S.length()-1&&S[low-1]==S[high+1]){
				low--;
				high++;
			}
			if(maxlen<high-low+1){
				maxlen=high-low+1;
				start=low;
				end=high;
			}

			if(S[i]==S[i+1]){
				high=i+1;
				low=i;
				while(low>0&&high<S.length()-1&&S[low-1]==S[high+1]){
					low--;
					high++;
				}
				if(maxlen<high-low+1){
					maxlen=high-low+1;
					start=low;
					end=high;
				}
			}
		}
		cout<<S.substr(start,maxlen)<<endl;
	}
}