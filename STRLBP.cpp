#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
 
int main(){
	int T;
	cin>>T;
	string s;
	while(T--){
		cin>>s;
		int count=0;
		for(int i=1;i<s.length();i++){
			if(s[i-1]!=s[i])
				count++;
		}
		if(s[s.length()-1]!=s[0])
			count++;
		if(count<=2)
			cout<<"uniform\n";
		else
			cout<<"non-uniform\n";
	}
}