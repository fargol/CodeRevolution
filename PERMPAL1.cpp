#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int main(){
	int T;
	string s;
	cin>>T;
	while(T--){
		cin>>s;
		char ch;
		vector<vector<int> > arr(26,vector<int>());
		for(int i=0;i<s.length();i++)
			arr[s[i]-97].push_back(i+1);
		int count=0;
		for(int i=0;i<26;i++){
			if(arr[i].size()&1){
				count++;
				ch=i+97;
			}
		}
		if(count==0){
			for(int i=0;i<26;i++){
				for(int j=0;j<arr[i].size()/2;j++)
					cout<<arr[i][j]<<" ";
			}
			for(int i=25;i>=0;i--){
				for(int j=0;j<arr[i].size()/2;j++)
					cout<<arr[i][arr[i].size()-j-1]<<" ";
			}
			cout<<endl;
		}
		else if(count==1){
			for(int i=0;i<26;i++){
				if(arr[i].size()%2==0){
				for(int j=0;j<arr[i].size()/2;j++)
					cout<<arr[i][j]<<" ";}
			}
			for(int i=0;i<arr[ch-97].size();i++)
				cout<<arr[ch-97][i]<<" ";
			for(int i=25;i>=0;i--){
				if(arr[i].size()%2==0){
				for(int j=0;j<arr[i].size()/2;j++)
					cout<<arr[i][arr[i].size()-j-1]<<" ";}
			}
			cout<<endl;
		}
		else
			cout<<"-1\n";
	}
}