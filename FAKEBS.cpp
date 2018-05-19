#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define MOD 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
#define push_back pb;
inline int BS(vii &A, int X, int N){
	int low=1,high=N,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(A[mid].first==X)
			return mid;
		else if(A[mid].first<X)
			low=mid+1;
		else
			high=mid-1;
	}
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(false);
	int T,N,Q,X,idx,low,high,mid,id,k;
	long long int swaps,swaps1;
	vii A(100010);
	vector<int> AA(100010);
	vii mids(20);
	cin>>T;
	while(T--){
		cin>>N>>Q;
		for(int i=1;i<=N;i++){
			cin>>AA[i];
			A[i].first=AA[i];
			//AB[i]=1;
			A[i].second=i;
		}
		sort(A.begin()+1,A.begin()+N+1);
		while(Q--){
			vector<int> AB(N+1,1);
			swaps=0;
			cin>>X;
			idx=BS(A,X,N);
			id=A[idx].second;
			low=1;high=N;
			k=0;
			while(low<=high){
				mid=(low+high)/2;
				if(mid==id){
					break;
				}
				else if(mid>id){
					high=mid-1;
					mids[k].first=mid;
					mids[k].second=-1;
					k++;
				}
				else{
					low=mid+1;
					mids[k].first=mid;
					mids[k].second=1;
					k++;
				}
			}
			int flag=0;
			for(int i=0;i<k;i++){
				if(AB[mids[i].first]==-1||(mids[i].second==1&&AA[mids[i].first]<X)||(mids[i].second==-1&&AA[mids[i].first]>X))
				{	//if(i==0)
						//cout<<"yaha\n";
					continue;}
				else{
					//if(i==0)
						//cout<<"yaha2\n";
					//swaps1=swaps;
					for(int j=0;j<k;j++){
						if(j==i||AB[mids[j].first]==-1)
							continue;
						//cout<<"-1here\n";
						if((mids[j].second==1&&AA[mids[j].first]<X)||(mids[j].second==-1&&AA[mids[j].first]>X))
							continue;
						else{
							//cout<<"0here\n";
							if((AA[mids[j].first]<X&&mids[j].second==-1)&&(AA[mids[i].first]>X&&mids[i].second==1)){
								AB[mids[j].first]=AB[mids[i].first]=-1;
								swaps++;
								//cout<<"1here\n";
								break;
							}
							if((AA[mids[j].first]>X&&mids[j].second==1)&&(AA[mids[i].first]<X&&mids[i].second==-1)){
								AB[mids[j].first]=AB[mids[i].first]=-1;
								swaps++;
								//cout<<"2here\n";
								break;
							}
						}
					}
					if(AB[mids[i].first]==1){
						if(AA[mids[i].first]<X&&mids[i].second==-1){
							for(int p=idx+1;p<N;p++){
								int z;
								for(z=0;z<k;z++){
									if(mids[z]==)
								}
								if(AB[A[p].second]==1){
									swaps++;
									//cout<<"3here\n";
									AB[A[p].second]=AB[mids[i].first]=-1;
									break;
								}
							}
						}
						if(AA[mids[i].first]>X&&mids[i].second==1){
							for(int p=idx-1;p>=1;p--){
								if(AB[A[p].second]==1){
									swaps++;
									//cout<<"4here\n";
									AB[A[p].second]=AB[mids[i].first]=-1;
									break;
								}
							}
						}
					}
					if(AB[mids[i].first]==1){
						flag=1;
						break;
					}
				}
			}
			if(flag==1)
				cout<<"-1\n";
			else
				cout<<swaps<<endl;
		}
	}
}