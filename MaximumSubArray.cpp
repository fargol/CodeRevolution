#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N,arr[500],max_sum,sum,sid,eid,psid;
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>arr[i];
		max_sum=INT_MIN;
		psid=sid=eid=0;
		sum=0;
		for(int i=0;i<N;i++){
			sum+=arr[i];
			if(arr[i]<0){
				sum=0;
				psid=i+1;
				//cout<<"here1 :: "<<psid<<endl;
				continue;
			}
			/*if(max_sum==sum){
				if(sid>psid){
					sid=psid;
					eid=i;
				}
			}*/
			if(max_sum<=sum){
				max_sum=sum;
				eid=i;
				sid=psid;
				//cout<<" i = "<<i<<" && here::"<<sid<<" "<<eid<<" :: sum = "<<sum<<endl
			}
		}
		//cout<<sid<<" "<<eid<<endl;
		for(int i=sid;i<=eid;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
}