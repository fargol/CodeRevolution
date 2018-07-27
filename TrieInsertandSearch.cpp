#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef struct node{
	char ch;
	node* children[26];
	bool endmark;
}NODE;
NODE* get(char alpha){
	NODE* n=new NODE;
	n->ch=alpha;
	for(int i=0;i<26;i++)
		n->children[i]=NULL;
	n->endmark=false;
	return n;	
}
void createTrie(string &S,NODE* Trie){
	NODE* curr=Trie;
	for(int i=0;i<S.length();i++){
		//cout<<i<<endl;
		if(curr->children[S[i]-'a']==NULL){
			curr->children[S[i]-'a']=get(S[i]);
		}
		curr=curr->children[S[i]-'a'];
	}
	curr->endmark=true;
}
bool searchTrie(string &S,NODE* Trie){
	NODE* curr=Trie;
	for(int i=0;i<S.length();i++){
		if(curr->children[S[i]-'a']==NULL){
			return false;
		}
		curr=curr->children[S[i]-'a'];
	}
	if(curr!=NULL){
		if(curr->endmark==true)
			return true;
		else
			return false;
	}
	else
		return false;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	string S;
	cin>>T;
	NODE* Trie=get('\0');
	bool res;
	while(T--){
		cin>>N;
		while(N--){
			cin>>S;
			createTrie(S,Trie);
		}
		cin>>S;
		res=searchTrie(S,Trie);
		if(res){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
}