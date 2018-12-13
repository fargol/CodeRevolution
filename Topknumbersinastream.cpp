#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define M 1000000007
int main(){
	ios::sync_with_stdio(true);
	int T,N,K;
	cin>>T;
	while(T--){
		cin>>N>>K;
		int arr[N];
		unordered_map<int,int> freq;
		vector<int> top(K+1);
		for(int i=0;i<N;i++){
			cin>>arr[i];
			if(freq.find(arr[i])!=freq.end()){
				freq[arr[i]]++;
			}
			else{
				freq[arr[i]]=1;
			}
			top[K]=arr[i];
			auto it=find(top.begin(),top.end(),arr[i]);
			for(int i=distance(top.begin(),it)-1;i>=0;i--){
				if(freq[top[i]]<freq[top[i+1]]){
					swap(top[i],top[i+1]);
				}
				else if(freq[top[i]]==freq[top[i+1]]){
					if(top[i]>top[i+1]){
						swap(top[i],top[i+1]);
					}
				}
				else{
					break;
				}
			}
			for(int i=0;i<K&&top[i]!=0;i++){
				cout<<top[i]<<" ";
			}
		}
		cout<<endl;
	}
}