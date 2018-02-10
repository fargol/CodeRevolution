#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int main(){
	int T,N,count,flag;
	char pr,cu;
	cin>>T;
	while(T--){
		cin>>N;
		vector<int> arr(N+1);
		for(int i=1;i<=N;i++)
			cin>>arr[i];
		if(arr[2]>arr[1])
			cu='l';
		else
			cu='g';
		count=0;
		for(int i=3;i<=N;i++){
			pr=cu;
			if(arr[i-1]<arr[i])
				cu='l';
			else
				cu='g';
			int temp,d;
			if(pr==cu){
				//cout<<"i:"<<i-1<<endl;
				if(cu=='l'){
					if(arr[N-i+1]<arr[N-i+2]){
						temp=arr[i-1];
						arr[i-1]=arr[N-i+2];
						arr[N-i+2]=temp;
					}
					else{
						temp=arr[i];
						arr[i]=arr[N-i+1];
						arr[N-i+1]=temp;
					}
				}
				else{
					if(arr[N-i+1]<arr[N-i+2]){
						temp=arr[i];
						arr[i]=arr[N-i+1];
						arr[N-i+1]=temp;
					}
					else{
						temp=arr[i-1];
						arr[i-1]=arr[N-i+2];
						arr[N-i+2]=temp;
					}
				}
				count++;
				if(arr[i-1]<arr[i])
					cu='l';
				else
					cu='g';
			}
		}
		if(arr[2]>arr[1])
			cu='l';
		else
			cu='g';
		flag=0;
		for(int i=3;i<=N;i++){
			pr=cu;
			if(arr[i-1]<arr[i])
				cu='l';
			else
				cu='g';
			if(pr==cu){
				flag=1;
				break;
			}
		}
		if(flag==1)
			cout<<"-1\n";
		else
			cout<<count<<endl;
	}
}
