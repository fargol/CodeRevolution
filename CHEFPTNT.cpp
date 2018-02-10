#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int main(){
	int T,N,M,X,K,ce,co;
	cin>>T;
	string S;
	while(T--){
		cin>>N>>M>>X>>K;
		cin>>S;
		if(M*X>=N){
			ce=count(S.begin(),S.end(),'E');
			//cout<<"ce: "<<ce<<endl;
			co=S.length()-ce;
			for(int i=1;i<=M&&N>0&&K>0;i++){
				if(i%2==1&&co>0){
					if(co<X){
						N-=co;
						K-=co;
						co=0;
					}
					else{
						N-=X;
						K-=X;
						co-=X;
					}
				}
				else if(i%2==0&&ce>0){
					if(ce<X){
						N-=ce;
						K-=ce;
						ce=0;
					}
					else{
						N-=X;
						K-=X;
						ce-=X;
					}
				}
			}
			if(N<=0)
				cout<<"yes\n";
			else
				cout<<"no\n";
		}
		else
			cout<<"no\n";
	}
}