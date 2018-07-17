#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
/*inline int inv_count(string S){
	set<char> mySet;
	mySet.insert(S[0]);
	int ic=0;
	set<char>::iterator itr;
	for(int i=1;i<S.length();i++){
		mySet.insert(S[i]);
		itr=mySet.upper_bound(S[i]);
		ic+=distance(itr,mySet.end());
	}
	return ic;
}*/
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(false);
	int T,N;
	long long int X,Y,XpY,Yi,min_XpY;
	string S;
	cin>>T;
	vector<vector<int> > before(100010,vector<int>(26)),after(100010,vector<int>(26));
	while(T--){
		cin>>S;
		min_XpY=LLONG_MAX;
		N=S.length();
		Yi=0;
		for(int j=0;j<26;j++){
			before[0][j]=0;
			after[N-1][j]=0;
		}
		for(int j=0;j<26;j++){
			for(int i=1;i<N;i++){
				before[i][j]=before[i-1][j];
				if((S[i-1]-'a')<j)
					before[i][j]++;
			}
		}
		for(int i=0;i<N;i++)
			Yi+=before[i][S[i]-'a'];
		//cout<<"Yi = "<<Yi<<endl;
		for(int j=0;j<26;j++){
			for(int i=N-2;i>=0;i--){
				after[i][j]=after[i+1][j];
				if((S[i+1]-'a')>j)
					after[i][j]++;
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<26;j++){
				X=abs(S[i]-'a'-j);
				Y=Yi-(before[i][S[i]-'a']+after[i][S[i]-'a'])+(before[i][j]+after[i][j]);
				XpY=X+Y;
				if(min_XpY>XpY)
					min_XpY=XpY;
			}
		}
		cout<<min_XpY<<endl;
	}
}