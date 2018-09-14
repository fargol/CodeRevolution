#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		int arr[N];
		for(int &i:arr)
			cin>>i;
		sort(arr,arr+N);
		map<string,bool> hm;
		for(int i=0;i<pow(2,N);i++){
			string str="";
			for(int j=0;j<N;j++){
				if(i&(1<<j))
					str+=to_string(arr[j]);
			}
			//cout<<"str = "<<str<<endl;
			hm[str]=true;
		}
		//cout<<"()";
		for(auto i=hm.begin();i!=hm.end();i++){
			cout<<"(";
			string str=i->first;
			int len=str.length();
			//cout<<"len = "<<str.length()<<endl;
			for(int j=0;j<len-1;j++)
				cout<<str[j]<<' ';
			if(len>0)
				cout<<str[len-1];
			cout<<")";
		}
		cout<<endl;
	}
}