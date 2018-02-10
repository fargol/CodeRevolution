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
		vector<pair<char,int> > arr(s.length());
		int carr[26]={0};
		for(int i=0;i<s.length();i++){
			arr[i].first=s[i];
			arr[i].second=i;
			carr[s[i]-97]++;
		}
		if(s.length()&1){
			int count=0;
			for(int i=0;i<26;i++){
				if(carr[i]&1){
					count++;
					ch=i+97;
				}
			}
			if(count!=1)
				cout<<"-1\n";
			else{
				sort(arr.begin(),arr.end());
				
				/*for(int i=0;i<s.length();i++){
					cout<<arr[i].first<<" "<<arr[i].second;
					cout<<" ; \n";
				}*/

				vector<int> starting(26,-1);
				vector<int> ending(26,-1);
				for(int i=0;i<s.length();i++){
					if(starting[arr[i].first-97]==-1)
						starting[arr[i].first-97]=i;
					ending[arr[i].first-97]=i;
				}
				for(int i=0;i<s.length();){
					if(carr[arr[i].first-97]%2==0){
					for(int j=0;j<carr[arr[i].first-97]/2;j++){
						cout<<arr[i].second+1<<" ";
						i++;
					}
					i=ending[arr[i].first-97]+1;}
					else
						i++;
				}
				/*for(int i=0;i<26;i++){
					char ch=(char)(i+97);
					if(starting[i]!=-1){
						
						cout<<ch<<":: starting - "<<starting[i]<<endl;
					}
					if(ending[i]!=-1)
						cout<<ch<<":: ending - "<<ending[i]<<endl;
				}*/
				//cout<<arr[s.length()-1].second+1<<" ";
				for(int i=starting[ch-97];i<=ending[ch-97];i++)
					cout<<i+1<<" ";
				for(int i=s.length()-1;i>=0;){
					if(carr[arr[i].first-97]%2==0){
					for(int j=0;j<carr[arr[i].first-97]/2;j++){
						cout<<arr[i].second+1<<" ";
						i--;
					}
					i=starting[arr[i].first-97]-1;}
					else
						i++;
				}
				cout<<endl;
			}
			cout<<"odd\n";
		}
		else{
			int count=0;
			for(int i=0;i<26;i++){
				if(carr[i]&1)
					count++;
			}
			if(count>0)
				cout<<"-1\n";
			else{
				sort(arr.begin(),arr.end());
				/*for(int i=0;i<s.length();i++){
					cout<<arr[i].first<<" "<<arr[i].second;
					cout<<" ; \n";
				}*/
				vector<int> starting(26,-1);
				vector<int> ending(26,-1);
				for(int i=0;i<s.length();i++){
					if(starting[arr[i].first-97]==-1)
						starting[arr[i].first-97]=i;
					//if(arr[i].first-97==1)
						//cout<<"spec: "<<starting[1]<<endl;
					ending[arr[i].first-97]=i;
				}
				/*for(int i=0;i<26;i++){
					char ch=(char)(i+97);
					if(starting[i]>-1){
						
						cout<<ch<<":: starting - "<<starting[i]<<endl;
					}
					if(ending[i]>-1)
						cout<<ch<<":: ending - "<<ending[i]<<endl;
				}*/
				for(int i=0;i<s.length();){
					for(int j=0;j<carr[arr[i].first-97]/2;j++){
						cout<<arr[i].second+1<<" ";
						i++;
					}
					i=ending[arr[i].first-97]+1;
				}
				//cout<<arr[s.length()-1].second<<" ";
				for(int i=s.length()-1;i>=0;){
					for(int j=0;j<carr[arr[i].first-97]/2;j++){
						cout<<arr[i].second+1<<" ";
						i--;
					}
					i=starting[arr[i].first-97]-1;
				}
				cout<<endl;
				cout<<"even\n";
			}
		}
	}
}