#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
struct NODE{
	NODE *next[26];
	char ch;
	bool end;
};
void createTrie(string s,NODE *Head){
	//cout<<"int Trie\n";
	NODE *curr=Head;
	for(int i=0;i<s.length();i++){
		if(curr->next[s[i]-'a']!=NULL){
			//cout<<"new "<<endl;
			curr=curr->next[s[i]-'a'];
			//cout<<"success\n";
		}
		else{
			curr->next[s[i]-'a']=new NODE;
			curr=curr->next[s[i]-'a'];
			curr->ch=s[i];
			for(int i=0;i<26;i++)
				curr->next[i]=NULL;
			//cout<<"new ch = "<<curr->ch<<endl;
		}
	}
	curr->end=true;
}
void displayALL(NODE *curr,string prefix){
	//cout<<"here:"<<prefix<<endl;
	if(curr->end==true){
		cout<<prefix<<" ";
		return;
	}
	string p;
	for(int i=0;i<26;i++){
		if(curr->next[i]!=NULL){
			p=prefix+(char)(i+'a');
			displayALL(curr->next[i],p);
		}
	}
}
void dfs(NODE *Head){
	cout<<"dfs: "<<Head->ch<<endl;
	for(int i=0;i<26;i++){
		if(Head->next[i]!=NULL){
			dfs(Head->next[i]);
		}
	}
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	string arr[100];
	string Q;
	cin>>T;
	while(T--){
		cin>>N;
		NODE *Head=new NODE;
		Head->ch='$';
		for(int i=0;i<26;i++)
			Head->next[i]=NULL;
		for(int i=0;i<N;i++){
			cin>>arr[i];
			createTrie(arr[i],Head);
		}
		//dfs(Head);
		cin>>Q;
		//cout<<Q<<endl;
		NODE *curr=Head;
		int i;
		for(i=0;i<Q.length();i++){
			if(curr->next[Q[i]-'a']!=NULL){
				curr=curr->next[Q[i]-'a'];
				displayALL(curr,Q.substr(0,i+1));
			}
			else{
				cout<<0<<endl;
				break;
			}
			cout<<endl;
		}
		for(i=i+1;i<Q.length();i++)
			cout<<0<<endl;
	}
}