#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int main(){
	long long int N,Q,pos,val,l,r,type,s3,s2,s1;
	long long int p;
	cin>>N>>Q;
	vector<long long int> A(N),B(N);
	for(long long int &i:A)
		cin>>i;
	while(Q--){
		cin>>type;
		if(type==1){
			cin>>pos>>val;
			pos--;
			A[pos]=val;
		}
		else{
			cin>>l>>r;
			l--;r--;
			for(long long int i=l;i<=r;i++)
				B[i]=A[i];
			sort(B.begin()+l,B.begin()+r+1);
			p=0;
			for(long long int i=r;i>=l+2;i--){
				s3=B[i];
				s2=B[i-1];
				s1=B[i-2];
				if(s1+s2>s3){
					p=s1+s2+s3;
					break;
				}
			}
			cout<<p<<endl;
		}
	}
}