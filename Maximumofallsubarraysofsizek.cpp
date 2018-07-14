#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,N,k;
	cin>>T;
	while(T--){
		cin>>N>>k;
		vector<int> arr(N);
		for(int &i:arr)
			cin>>i;
		deque<int> dq;
		for(int i=0;i<k;i++){
			while(!dq.empty()&&arr[dq.back()]<=arr[i])
				dq.pop_back();
			dq.push_back(i);
		}
		for(int i=k;i<N;i++){
			cout<<arr[dq.front()]<<" ";
			while(!dq.empty()&&dq.front()<=i-k)
				dq.pop_front();
			while(!dq.empty()&&arr[dq.back()]<=arr[i])
				dq.pop_back();
			dq.push_back(i);
		}
		cout<<arr[dq.front()]<<endl;
	}
}