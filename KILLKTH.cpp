#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main(){
	long long int P,M,Q,G,K;
	string S;
	cin>>S;
	cin>>Q;
	long long int size=pow(S.size(),2);
	size+=S.size();
	size/=2;
	string SS="";
	vector<string> arr(size);
	int k=0;
	for(int i=1;i<=S.size();i++){
		for(int j=0;j+i-1<S.size();j++){
			arr[k]=S.substr(j,i);
			k++;
		}
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<size;i++)
		SS+=arr[i];
	//cout<<SS<<endl;
	G=0;
	while(Q--){
		cin>>P>>M;
		K=(P*G)%M+1;
		cout<<SS[K-1]<<endl;
		G+=SS[K-1];
	}
}