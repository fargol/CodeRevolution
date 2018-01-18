#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
 
int main(){
	int T,N,M,count;
	string A,B;
	cin>>T;
	while(T--){
		cin>>N>>M;
		cin>>A>>B;
		int arr[26]={0};
		for(int i=0;i<N;i++)
			arr[A[i]-97]++;
		for(int i=0;i<M;i++)
			arr[B[i]-97]++;
		/*for(int i=0;i<26;i++)
			cout<<i<<":"<<arr[i]<<" ";
		cout<<endl;*/
		count=0;
		for(int i=0;i<26;i++){
			if(arr[i]>0)
				count++;
		}
		cout<<count<<endl;
	}
}