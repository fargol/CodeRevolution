#include <bits/stdc++.h>
using namespace std;
// #define endl '\n'
#define ll long long
#define M 1000000007
int main(){
	srand(time(NULL));
	ios::sync_with_stdio(true);
	int X,Y,Z;
	X=rand()%3+1;
	cout<<X<<endl;
	cin>>Y;
	Z=6/(X*Y);
	cout<<Z<<endl;
}