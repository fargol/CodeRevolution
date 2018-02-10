#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	string s,str;
	int count,i;
	cin>>T;
	while(T--){
		count=0;
		cin>>s;
		for(i=0;i<s.length();i++){
			str=s.substr(i,4);
			//cout<<str<<endl;
			sort(str.begin(),str.end());
			if(str=="cefh")
				count++;
		}
		if(count>0)
			cout<<"lovely "<<count<<endl;
		else
			cout<<"normal\n";
	}
}