#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
//typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,i;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>N;
		vector<int> L(N);
		for(int &i:L)
			cin>>i;
		bool done = false;
    	while (!done){
      		done = true;
      		for(i = 0; i < N-2; i++){
        		if(L[i] > L[i+2]){
          			done = false;
          			int temp=L[i];
          			L[i]=L[i+2];
          			L[i+2]=temp;
          		}
          	}
        }
        vector<int> arr=L;
        sort(arr.begin(),arr.end());
        for(i=0;i<N;i++){
        	if(arr[i]!=L[i])
        		break;
        }
        if(i==N)
        	printf("Case #%d: OK\n",t);
        else
        	printf("Case #%d: %d\n",t,i);
	}
}