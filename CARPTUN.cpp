#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int main(){
	int T,N,C,D,S;
	double delay;
	cin>>T;
	while(T--){
		cin>>N;
		vector<int> arr(N);
		for(int &i:arr)
			cin>>i;
		cin>>C>>D>>S;
		delay=arr[0];
		for(int i=1;i<N;i++){
			if(delay<arr[i])
				delay+=arr[i]-delay;
		}
		delay=delay*(C-1);
		printf("%.9lf\n",delay);
	}
}