#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
//typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	//ios::sync_with_stdio(false);
	int T,D,count,j;
	string P;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>D>>P;
		count=0;
		vector<int> arr(P.length()+1);
		if(P[0]=='S'){
			arr[0]=1;
			arr[P.length()]=arr[0];
		}
		else{
			arr[0]=2;
			arr[P.length()]=0;
		}
		//j=INT_MIN;
		for(int i=1;i<P.length();i++){
			if(P[i]=='S'){
				arr[i]=arr[i-1];
				arr[P.length()]+=arr[i];
			}
			else
				arr[i]=arr[i-1]*2;
		}
		if(arr[P.length()]<=D){
			printf("Case #%d: %d\n",t,0);
			continue;
		}
		else{
			while(arr[P.length()]>D){
				count++;
				int i;
				for(i=P.length()-1;i>0;i--){
					if(P[i]=='S'&&P[i-1]=='C'){
						P[i]='C';
						//cout<<" P = "<<P<<" && i = "<<i<<endl;
						P[i-1]='S';
						//cout<<" P = "<<P<<" && i = "<<i<<endl;
						arr[P.length()]-=arr[i-1]/2;
						arr[i-1]/=2;
						break;
					}
				}
				if(i==0)
					break;
				//cout<<"Count = "<<count<<" && val = "<<arr[P.length()]<<" && P = "<<P<<endl;
			}
			if(arr[P.length()]>D)
				printf("Case #%d: Impossible\n",t);
			else
				printf("Case #%d: %d\n",t,count);
		}
	}
}