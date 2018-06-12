#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef struct node{
	string ch;
	node* alpha[26];
	bool end;
}NODE;
typedef NODE* NODEPTR;

void setNODE(NODEPTR node){
	node->ch='\0';
	for(int i=0;i<26;i++)
		node->alpha[i]=NULL;
	node->end=false;
}

void insert(NODEPTR root,string str){
	for(int i=0;i<str.length();i++){
		if(root->alpha[str[i]-'a']==NULL){
			root->alpha[str[i]-'a']=(NODEPTR)malloc(sizeof(NODE));
			setNODE(root->alpha[str[i]-'a']);
			root->alpha[str[i]-'a']->ch=str[i];
		}
		root=root->alpha[str[i]-'a'];
	}
	root->end=true;
}

int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	//ios::sync_with_stdio(false);
	int N,Q;
	cin>>N;
	vector<string> arr(N);
	
	NODEPTR root=(NODEPTR)malloc(sizeof(NODE));
	setNODE(root);

	for(int i=0;i<N;i++){
		cin>>arr[i];
		//insert(root,arr[i]);
	}
	/*cout<<"\nArr = \n";
	for(int i=0;i<N;i++)
		cout<<arr[i]<<endl;*/

	cin>>Q;
	//cout<<"\nQ = "<<Q<<endl;
	vector<tuple<int,string,int> > queries(Q);
	vector<string> answers(Q);
	int range,index;
	string word;
	for(int i=0;i<Q;i++){
		cin>>range>>word;
		range--;
		queries[i]=make_tuple(range,word,i);
	}
	sort(queries.begin(),queries.end());

	/*cout<<"Sorted Queries:- \n";
	for(int i=0;i<Q;i++)
		cout<<get<0>(queries[i])<<" "<<get<1>(queries[i])<<endl;*/

	int initial=0;
	NODEPTR current;
	for(int i=0;i<Q;i++){
		current=root;
		string ans="";
		range=get<0>(queries[i]);
		word=get<1>(queries[i]);
		index=get<2>(queries[i]);

		//cout<<"\nrange = \n"<<range<<endl;
		//cout<<"\ninitial = \n"<<initial<<endl;
		//if(i==2)
			//break;
		for(int j=initial;j<=range;j++){
			//cout<<"INSERTED WORD = "<<arr[j]<<endl;
			insert(root,arr[j]);
		}
		initial=range+1;
		for(int j=0;j<word.length();j++){
			//cout<<"\nchar = "<<current->ch<<endl;
			if(current->alpha[word[j]-'a']==NULL){
				//cout<<"here1\n";
				break;
			}
			else{
				//cout<<"here2\n";
				current=current->alpha[word[j]-'a'];
				ans+=current->ch;
			}
		}
		while(current->end==false){
			int k=0;
			while(current->alpha[k]==NULL&&k<26)
				k++;
			if(k<26){
				current=current->alpha[k];
				ans+=current->ch;
			}
		}
		//cout<<"\nans = "<<ans<<endl
		answers[index]=ans;
	}
	for(int i=0;i<Q;i++)
		cout<<answers[i]<<endl;
}