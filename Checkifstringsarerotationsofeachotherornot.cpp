#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
void getLPS(string pat,int lps[]){
	lps[0]=0;
	int len=0;
	int i=1;
	while(i<pat.length()){
		if(pat[i]==pat[len]){
			len++;
			lps[i]=len;
			i++;
		}
		else{
			if(len!=0){
				len=lps[len-1];
			}
			else{
				lps[i]=0;
				i++;
			}
		}
	}
}
bool searchPattern(string txt,string pat,int lps[]){
	int i=0,j=0;
	while(i<txt.length()){
		if(txt[i]==pat[j]){
			i++;
			j++;
		}
		if(j==pat.length())
			return true;
		else if (i<txt.length()&&pat[j]!=txt[i]) {
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
	}
	return false;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T;
	string S1,S2;
	cin>>T;
	while(T--){
		cin>>S1>>S2;
		if(S1.length()!=S2.length()){
			cout<<0<<endl;
			continue;
		}
		S1+=S1;
		int lps[S2.length()];
		getLPS(S2,lps);
		cout<<searchPattern(S1,S2,lps)<<endl;
	}
}