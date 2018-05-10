#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int main(){
	ios::sync_with_stdio(true);
	int T;
	cin>>T;
	string S;
	int h,p,flag,max;
	while(T--){
		cin>>S;
		h=0;
		p=0;
		//flag=0;
		max=INT_MIN;
		for(int i=0;i<S.length();i++){
			if(S[i]=='('){
				h++;
				//flag=1;
			}
			else if(h>0){
				h--;
				p++;
			}
			if(h==0){
				if(max<p)
					max=p;
				p=0;
			}
		}
		if(max<p)
			max=p;
		cout<<2*max<<endl;
	}
}