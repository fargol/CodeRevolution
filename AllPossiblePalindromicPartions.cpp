#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
void printAll(bool P[][999],int b,string S,string res,int N,int h){
	if(b==N)
		cout<<res<<endl;
	string temp=res;
	for(int i=b;i<N;i++){
		res=temp;
		if(P[b][i]){
			res+=S.substr(b,i+1-b)+" ";
			printAll(P,i+1,S,res,N,h+1);
		}
	}
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T;
	string S;
	cin>>T;
	bool P[999][999];
	while(T--){
		cin>>S;
		int N=S.length();
		for(int i=0;i<N;i++)
			P[i][i]=true;
		for(int l=2;l<=N;l++){
			for(int i=0;i<=N-l;i++){
				int j=i+l-1;
				if(l==2)
					P[i][j]=(S[i]==S[j]);
				else
					P[i][j]=(S[i]==S[j])&&P[i+1][j-1];
			}
		}
		string res;
		for(int i=0;i<N;i++){
			if(P[0][i]){
				res=S.substr(0,i+1)+" ";
				printAll(P,i+1,S,res,N,0);
			}
		}
	}
}