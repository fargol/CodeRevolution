#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
string LCP(string s1,string s2){
	string Lcp="";
	int l=min(s1.length(),s2.length());
	for(int j=0;j<l;j++){
		if(s1[j]==s2[j])
			Lcp+=s1[j];
		else
			break;
	}
	return Lcp;
}
void bs(int low,int high, int id, string query, string arr){
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		while(id<query.length()&&id<arr[mid].length()){
			if(arr[mid][id]==a)
		}
	}
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(false);
	int N,Q,R,maxl;
	cin>>N;
	//cout<<"★"<<endl;
	int count[100010];
	string arr[100010];
	string lcp[100010];
	string query,Lcp,ans;
	cin>>arr[1];
	//lcp[1]=arr[1];
	for(int i=2;i<=N;i++){
		cin>>arr[i];
		//lcp[i]=LCP(arr[i],lcp[i-1]);
	}
	cin>>Q;
	for(int i=1;i<=Q;i++){
		cin>>R>>query;
		//Lcp=LCP(lcp[R],query);
		sort(arr+1,arr+R+1);
		int low=1,high=R,mid,id=0;
		while(low<=high){
			mid=(low+high)/2;
			while(id<query.length()&&id<arr[mid].length()){
				if(query[id]==arr[mid][id])
					id++;
				else
					break;
			}
			if(id<query.length()){
				if(id<arr[mid-1].length()){
					if(mid>1&&arr[mid-1][id]>=query[id])
						high=mid-1;
					else if(mid<R&&arr[mid+1][id]==query[id])
						low=mid+1;
					else{
						ans=mid;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}