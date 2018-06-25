#include <bits/stdc++.h>
using namespace std;
int main(){
	int T,x,N,M;
	cin>>T;
	vector<string> dict(10);
	vector<vector<char> > boggle(10,vector<char>(10));
	vector<vector<bool> > graph(26,vector<bool>(26,false));
	vector<int> count(26),orig_count(26);
	while(T--){
		cin>>x;
		for(int i=0;i<26;i++){
			orig_count[i]=0;
			for(int j=0;j<26;j++)
				graph[i][j]=false;
		}
		for(int i=0;i<x;i++)
			cin>>dict[i];
		sort(dict.begin(),dict.end());
		cin>>N>>M;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				cin>>boggle[i][j];
				orig_count[toupper(boggle[i][j])-'A']++;
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(i>0){
					graph[toupper(boggle[i][j])-'A'][toupper(boggle[i-1][j])-'A']=true;
					if(j>0)
						graph[toupper(boggle[i][j])-'A'][toupper(boggle[i-1][j-1])-'A']=true;
					if(j<M-1)
						graph[toupper(boggle[i][j])-'A'][toupper(boggle[i-1][j+1])-'A']=true;
				}
				if(j>0){
					graph[toupper(boggle[i][j])-'A'][toupper(boggle[i][j-1])-'A']=true;
					if(i<N-1)
						graph[toupper(boggle[i][j])-'A'][toupper(boggle[i+1][j-1])-'A']=true;
				}
				if(i<N-1){
					graph[toupper(boggle[i][j])-'A'][toupper(boggle[i+1][j])-'A']=true;
					if(j<M-1)
						graph[toupper(boggle[i][j])-'A'][toupper(boggle[i+1][j+1])-'A']=true;
				}
				if(j<M-1)
					graph[toupper(boggle[i][j])-'A'][toupper(boggle[i][j+1])-'A']=true;
			}
		}
		int flag=0;
		string str;
		for(int i=0;i<x;i++){
			int j=0;
			count=orig_count;
			str=dict[i];
			transform(str.begin(), str.end(), str.begin(), ::toupper);
			while(j<str.length()){
				if(count[str[j]-'A']){
					count[str[j]-'A']--;
					if((j<str.length()-1)&&graph[str[j]-'A'][str[j+1]-'A'])
						j++;
					else
						break;
				}
				else
					break;
			}
			if(j==str.length()-1){
				cout<<dict[i]<<" ";	
				flag++;
			}
		}
		if(flag==0)
			cout<<-1;
		cout<<endl;
	}
}