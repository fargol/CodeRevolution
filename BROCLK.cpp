#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define PI 3.14159265
int main(){
	int T;
	long long int d,l,t,dist;
	long double x,rt,qt;
	long double param;
	cin>>T;
	while(T--){
		cin>>d>>l>>t;
		param=(d*1.0)/l;
		x=acos(param);
		//x*=180.0/PI;
		rt=2*PI;
		rt/=x;
		qt=PI/x;
		qt/=2;
		t%=rt;
		dist=cos(t*x);
		dist*=l;
	}
}