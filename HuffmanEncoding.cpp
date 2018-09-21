#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;

class NODE
{
public:
	char ch;
	int freq;
	NODE *left;
	NODE *right;
};

class Compare
{
public:
    bool operator() (const NODE *a, const NODE *b)
    {
        return a->freq>b->freq;
    }
};

void preorder(NODE *head,string code){
	if(head==NULL)
		return;
	if(head->left==NULL&&head->right==NULL){
		cout<<code<<" ";
		return;
	}
	preorder(head->left,code+'0');
	preorder(head->right,code+'1');
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T;
	cin>>T;
	while(T--){
		string S;
		cin>>S;
		int freq[S.length()];
		for(int &i:freq)
			cin>>i;
		NODE arr[S.length()];
		for(int i=0;i<S.length();i++){
			arr[i].ch=S[i];
			arr[i].freq=freq[i];
			arr[i].left=NULL;
			arr[i].right=NULL;
		}
		priority_queue<NODE*,vector<NODE*>,Compare> Q;
		for(int i=0;i<S.length();i++){
			Q.push(&arr[i]);
		}

		NODE *head,*L,*R,*curr;
		while(Q.size()>1){
			L=Q.top();
			Q.pop();
			R=Q.top();
			Q.pop();
			curr=new NODE;
			curr->freq=L->freq+R->freq;
			curr->left=L;
			curr->right=R;
			Q.push(curr);
		}
		head=Q.top();
		Q.pop();
		string code="";
		preorder(head,code);
		cout<<endl;
	}
}