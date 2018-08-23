#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,arr[5000],f,e;
	cin>>T;
	while(T--){
		cin>>N;
		unordered_map<int,int> freq;
		for(int i=0;i<N;i++){
			cin>>arr[i];
			if(freq.find(arr[i])==freq.end())
				freq[arr[i]]=1;
			else
				freq[arr[i]]++;
		}	
		map<int,vector<int> > freq_detect;
		for(auto i=freq.begin();i!=freq.end();i++){
			f=i->second;
			e=i->first;
			freq_detect[f].push_back(e);
			//cout<<"f = "<<f<<" & e = "<<e<<endl;
		}
		for(auto i=freq_detect.begin();i!=freq_detect.end();i++){
			/*cout<<"here\n";
			for(int j=0;j<i->second.size();j++)
				cout<<i->second[j]<<" ";
			cout<<endl;*/
			sort(i->second.begin(),i->second.end());
		}
		for(auto i=freq_detect.rbegin();i!=freq_detect.rend();i++){
			for(int j=0;j<i->second.size();j++){
				for(int k=0;k<i->first;k++)
					cout<<i->second[j]<<" ";
			}
		}
		cout<<endl;
	}
}