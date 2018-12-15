#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define M 1000000007
void createJump(vector<int> &arr,string res,int idx,int X){
	// if(d==0){
	// 	cout<<"res = "<<res<<endl;
	// 	arr.push_back(stoi(res));
	// 	return;
	// }
	string str;
	if(res[idx]=='0'){
		str=res;
		str+=res[idx]+1;
		//cout<<"str = "<<str<<endl;
		if(stoi(str)<=X){
			arr.push_back(stoi(str));
			createJump(arr,str,idx+1,X);
		}
	}
	if(res[idx]>='1'&&res[idx]<='8'){
		str=res;
		str+=res[idx]-1;
		//cout<<"str = "<<str<<endl;
		if(stoi(str)<=X){
			arr.push_back(stoi(str));
			createJump(arr,str,idx+1,X);
		}
		str=res;
		str+=res[idx]+1;
		//cout<<"str = "<<str<<endl;
		if(stoi(str)<=X){
			arr.push_back(stoi(str));
			createJump(arr,str,idx+1,X);
		}
	}
	if(res[idx]=='9'){
		str=res;
		str+=res[idx]-1;
		//cout<<"str = "<<str<<endl;
		if(stoi(str)<=X){
			arr.push_back(stoi(str));
			createJump(arr,str,idx+1,X);
		}
	}
}
int main(){
	ios::sync_with_stdio(true);
	int T,X;
	cin>>T;
	while(T--){
		cin>>X;
		// int d=0;
		// int N=X;
		// while(N>0){
		// 	N/=10;
		// 	d++;
		// }
		// cout<<"d = "<<d<<endl;
		vector<int> arr;
		for(int i=0;i<=9;i++){
			arr.push_back(i);
		}
		// if(d>1){
			string res="";
			for(int i=1;i<=9;i++){
				res="";
				res+=to_string(i);
				createJump(arr,res,0,X);
			}
		// }
		sort(arr.begin(),arr.end());
		for(int i=0;i<arr.size()&&arr[i]<=X;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
}