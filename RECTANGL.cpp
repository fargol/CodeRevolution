#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int T;
	cin>>T;
	vector<int> arr(4);
	while(T--){
		for(int &i:arr)
			cin>>i;
		sort(arr.begin(),arr.end());
		if(arr[0]==arr[1]&&arr[2]==arr[3])
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}