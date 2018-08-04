#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int N,X;
	cin>>N;
	priority_queue<int> MaxHeap;
	priority_queue <int, vector<int>, greater<int> > MinHeap;
	int median=INT_MAX;
	while(N--){
		cin>>X;
		if(X>=median)
			MinHeap.push(X);
		else
			MaxHeap.push(X);
	
		if(MaxHeap.size()<MinHeap.size()){
			MaxHeap.push(MinHeap.top());
			MinHeap.pop();
		}
		else if(MaxHeap.size()>MinHeap.size()){
			MinHeap.push(MaxHeap.top());
			MaxHeap.pop();
		}
		if(MaxHeap.size()==MinHeap.size())
			median=(MaxHeap.top()+MinHeap.top())/2;
		else if(MaxHeap.size()<MinHeap.size())
			median=MinHeap.top();
		else
			median=MaxHeap.top();
		cout<<median<<endl;
	}
}