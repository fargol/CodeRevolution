#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 1000000007
#define ll long long
int main(){
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		int twos=0,fives=0;
		for(int i=N;i>=2;i--){
			int j=i;
			while(j%2==0){
				j>>=1;
				twos++;
			}
			j=i;
			while(j%5==0){
				j/=5;
				fives++;
			}
		}
		cout<<min(twos,fives)<<endl;
	}
}