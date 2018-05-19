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
	int T,N,Q,X,idx,low,high,mid,id,i,j,k,z,temp;
	long long int swaps;
	vii A(100010);
	vii AA(100010);
	cin>>T;
	while(T--){
		cin>>N>>Q;
		for(i=1;i<=N;i++){
			cin>>AA[i].first;
			AA[i].second=-1;
			A[i].first=AA[i].first;
			A[i].second=i;
		}
		sort(A.begin()+1,A.begin()+N+1);
		while(Q--){
			vector<int> mids(20);
			for(i=1;i<=N;i++)
				AA[i].second=-1;
			cin>>X;
			swaps=0;
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
					mids[k]=mid;
					k++;
				}
				else{
					low=mid+1;
					mids[k]=mid;
					k++;
				}
			}
			sort(mids.begin(),mids.begin()+k);
			int flag=0;
			for(i=0;i<k;i++){
				if(AA[mids[i]].second==-1&&mids[i]<id&&AA[mids[i]].first>X){
					for(j=0;j<k;j++){
						if(i!=j){
							if(AA[mids[j]].second==-1&&mids[j]>id&&AA[mids[j]].first<X){
								swaps++;
								AA[mids[i]].second=1;
								AA[mids[j]].second=1;
								break;
							}
						}
					}
					if(j>=k){
						for(z=idx-1;z>=1;z--){
							if(AA[A[z].second].second==-1){
								if(!binary_search(mids.begin(),mids.begin()+k,A[z].first)){
									swaps++;
									AA[mids[i]].second=1;
									AA[A[z].second].second=1;
									break;
								}
							}
						}
						if(z<=0){
							flag=1;
							break;
						}
					}
				}
				if(AA[mids[i]].second==-1&&mids[i]>id&&AA[mids[i]].first<X){
					for(j=0;j<k;j++){
						if(i!=j){
							if(AA[mids[j]].second==-1&&mids[j]<id&&AA[mids[j]].first>X){
								swaps++;
								AA[mids[i]].second=AA[mids[j]].second=1;
								break;
							}
						}
					}
					if(j>=k){
						for(z=idx+1;z<N+1;z++){
							if(AA[A[z].second].second=-1){
								if(!binary_search(mids.begin(),mids.begin()+k,A[z].first)){
									swaps++;
									AA[mids[i]].second=AA[A[z].second].second=1;
									break;
								}
							}
						}
						if(z>=N+1){
							flag=1;
							break;
						}
					}
				}
			}
			if(flag==0){
				cout<<swaps<<endl;
			}
			else{
				cout<<-1<<endl;
			}
		}
	}
}