#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,temp;
	int j=65;
	vector<char> dp(27);
	for(int i=1;i<=26;i++){
		dp[i]=(char)j;
		j++;
	}
	cin>>T;
	string out;
	while(T--){
		cin>>N;
		temp=N;
		out="";
		vector<char> arr;
		while(temp){
			if(temp%26==0){
				arr.push_back(dp[26]);
				temp-=26;
				temp/=26;
			}
			else{
				arr.push_back(dp[temp%26]);
				temp/=26;
			}
		}
		for(int i=arr.size()-1;i>=0;i--)
			cout<<arr[i];
		cout<<endl;
	}
}