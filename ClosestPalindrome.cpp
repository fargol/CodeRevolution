#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T;
	cin>>T;
	vector<char> arr1(16);
	vector<char> arr2(16);
	string N,s1,s2;
	unsigned long long int N12,N1,N2; 
	while(T--){
		cin>>N;
		int d=N.length();
		int j=0;
		for(int i=d-1;i>=0;i--){
			arr1[i]=N[j];
			j++;
		}
		for(int i=0;i<=d/2;i++){
			arr1[i]=arr1[d-1-i];
		}
		if(d&1){
			int j=0;
			for(int i=d-1;i>=0;i--){
				arr2[i]=N[j];
				j++;
			}
			for(int i=0;i<d/2;i++){
				arr2[i]=arr2[d-1-i];
			}
			if(arr2[d/2]>'0')
				arr2[d/2]-=1;
		}
		s1="";s2="";
		for(int i=d-1;i>=0;i--){
			s1+=arr1[i];
			s2+=arr2[i];
		}
		N12=stoll(N);
		N1=stoll(s1);
		N2=stoll(s2);
		if(abs(N-s1)<abs(N12-N2))
			cout<<N1;
		else
			cout<<N2;
		cout<<endl;
	}
}