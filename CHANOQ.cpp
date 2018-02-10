#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define PI 3.14159265
int b_s1(int e,vector<int> &quer){
	if (e <= quer[0])
        return 0;
    if (e > quer[quer.size() - 1])
        return -1;
	int h,l,mid;
	l=0;
	h=quer.size()-1;
	int idx;
	while(l<=h){
		mid=(l+h)/2;
		if(quer[mid]==e)
			return mid;
		else if(e<quer[mid]){
			h=mid-1;
			if(mid-1>-1&&e>quer[mid-1])
				return mid;
		}
		else{
			l=mid+1;
			if(mid+1<quer.size()&&e<quer[mid+1])
				return mid+1;
		}
	}
	return -1;
}
int b_s2(int e,vector<int> &quer){
	if (e < quer[0])
        return -1;
    if (e >= quer[quer.size() - 1])
        return (quer.size() - 1);
	int h,l,mid;
	l=0;
	h=quer.size()-1;
	int idx;
	while(l<=h){
		mid=(l+h)/2;
		if(quer[mid]==e)
			return mid;
		else if(e<quer[mid]){
			h=mid-1;
			if(mid-1>-1&&e>quer[mid-1])
				return mid-1;
		}
		else{
			l=mid+1;
			if(mid+1<quer.size()&&e<quer[mid+1])
				return mid;
		}
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
	int T;
	int N,Q,L,R,M,X;
	cin>>T;
	//cout<<"T:"<<T<<endl;
	while(T--){
		cin>>N;
		vector<pair<int,int> > limits(100001);
		for(int i=0;i<100001;i++){
			limits[i].first=-2;
			limits[i].second=-2;
		}
		vector<pair<int,int> > arr(N);
		for(int i=0;i<N;i++)
			cin>>arr[i].first>>arr[i].second;
		/*for(int i=0;i<N;i++){
			cout<<"L:"<<arr[i].first;
			cout<<":: R:"<<arr[i].second<<endl;
		}*/
		cin>>Q;
		for(int i=0;i<Q;i++){
			//cout<<"Query :"<<i+1<<endl;
			cin>>M;
			vector<int> quer(M);
			for(int &i:quer)
				cin>>i;
			sort(quer.begin(),quer.end());
			/*for(int i=0;i<quer.size();i++)
				cout<<" q:, "<<quer[i];*/
			//cout<<endl;
			int count=0,l,r;
			for(int i=0;i<N;i++){
				if(limits[arr[i].first].first==-2){
					l=b_s1(arr[i].first,quer);
					limits[arr[i].first].first=l;
				}
				else
					l=limits[arr[i].first].first;
				if(limits[arr[i].second].second==-2){
					r=b_s2(arr[i].second,quer);
					limits[arr[i].second].second=r;
				}
				else
					r=limits[arr[i].second].second;
				//cout<<"e: "<<arr[i].first<<" ::l:"<<l<<"  && e: "<<arr[i].second<<" ::r:"<<r<<endl;
				if(l!=-1&&r!=-1&&((r-l+1)%2==1))
					count++;
			}
			cout<<count<<endl;
		}
	}
}