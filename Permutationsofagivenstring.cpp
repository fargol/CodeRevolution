#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
void generate_perm(char *S,vector<string> &perm,int l,int r){
	if(l==r){
		string ss="";
		for(int i=0;i<strlen(S);i++)
			ss+=S[i];
		perm.push_back(ss);
	}
	for(int i=l;i<=r;i++){
		char temp=S[i];
		S[i]=S[l];
		S[l]=temp;
		generate_perm(S,perm,l+1,r);
		temp=S[l];
		S[l]=S[i];
		S[i]=temp;
	}
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T;
	char S[6];
	cin>>T;
	while(T--){
		scanf("%s",S);
		vector<string> perm;
		generate_perm(S,perm,0,strlen(S)-1);
		sort(perm.begin(),perm.end());
		for(string &i:perm)
			cout<<i<<" ";
		cout<<endl;
	}
}