#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
inline bool cmp(const int a,const int b){
	return (a>b);
}
int main(){
	ios::sync_with_stdio(true);
	int T,N,K,S[100001];
	cin>>T;
	while(T--){
		cin>>N>>K;
		for(int i=0;i<N;i++)
			cin>>S[i];
		sort(S,S+N,cmp);
		int idx=-1;
		for(int i=K-1;i<N-1;i++){
			if(S[i]!=S[i+1]){
				idx=i;
				break;
			}
		}
		if(idx!=-1){
			cout<<(idx+1)<<endl;
		}
		else{
			cout<<N<<endl;
		}
		/*int val=S[K-1];
		int low=K-1,high=N-1,mid,idx;
		while(low<=high){
			mid=(low+high)/2;
			if(S[mid]==val){
				if(mid<N-1){
					if(S[mid+1]!=val){
						idx=mid;
						break;
					}
					else{
						low=mid+1;
					}
				}
				else{
					idx=N-1;
					break;
				}
			}
			if(S[mid]>val){
				high=mid-1;
			}
		}
		val=idx+1;
		cout<<val<<endl;*/
	}
}