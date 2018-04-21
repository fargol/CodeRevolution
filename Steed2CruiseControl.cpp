#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<long long int, long long int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<long long int, ii> > EdgeList;
	ios::sync_with_stdio(false);
	long long int T,D,N;
	double time,ttime,speed,delk,dels;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>D>>N;
		time=0;
		vector<pair<double,double> > H(N);
		for(int i=0;i<N;i++)
			cin>>H[i].first>>H[i].second;
		sort(H.begin(),H.end());
		int i=1;
		while(i<N&&H[i].first<D){
			if(H[0].second>H[i].second){
				delk=(H[i].first-H[0].first);
				dels=(H[0].second-H[i].second);
				ttime=delk/dels;
				H[0].first+=ttime*H[0].second;
				H[0].second=H[i].second;
				time+=ttime;
				i++;
				if(i<N)
					H[i].first+=ttime*H[i].second;
			}
			else
				break;
		}
		if(H[0].first<D)
			time+=(D-H[0].first)/H[0].second;
		speed=D/time;
		printf("Case #%d: %.12lf\n",t,speed);
	}
}