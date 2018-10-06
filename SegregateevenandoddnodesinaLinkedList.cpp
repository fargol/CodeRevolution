#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
struct Node{
	int data;
	Node *next;
};
void printList(Node *head){
	Node *curr=head;
	while(curr!=NULL){
		cout<<curr->data<<" ";
		curr=curr->next;
	}
	cout<<endl;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		Node *head=new Node;
		Node *prev=NULL,*curr=NULL;
		cin>>head->data;
		head->next=NULL;
		prev=head;
		for(int i=1;i<N;i++){
			curr=new Node;
			cin>>curr->data;
			prev->next=curr;
			prev=curr;
			curr->next=NULL;
			curr=curr->next;
		}
		//cout<<"Orig List:\n";
		//printList(head);
		curr=head;
		Node *oddHead=NULL,*evenHead=NULL,*evenPrev=NULL,*oddPrev=NULL;
		while(curr!=NULL){
			if(curr->data%2==0){
				if(evenHead==NULL){
					evenHead=curr;
				}
				else{
					evenPrev->next=curr;
				}
				evenPrev=curr;
			}
			else{
				if(oddHead==NULL){
					oddHead=curr;
				}
				else{
					oddPrev->next=curr;
				}
				oddPrev=curr;
			}
			curr=curr->next;
		}
		if(evenPrev!=NULL){
			evenPrev->next=oddHead;
			if(oddPrev!=NULL)
				oddPrev->next=NULL;
			//cout<<"New List:\n";
			printList(evenHead);
		}
		else{
			//cout<<"New List:\n";
			printList(oddHead);
		}
	}
}
