#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int main(){
	ios::sync_with_stdio(false);
	int T;
	int N;
	cin>>T;
	while(T--){
		double loss=0;
		double TotalLoss=0;
		cin>>N;
		vector<double> P(N);
		vector<double> Q(N);
		vector<double> D(N);
		for(int i=0;i<N;i++){
			cin>>P[i]>>Q[i]>>D[i];
			loss=P[i]*(pow(D[i],2));
			loss*=Q[i];
			loss/=10000.0;
			TotalLoss+=loss;
		}
		printf("%.6lf\n",TotalLoss);
	}
}