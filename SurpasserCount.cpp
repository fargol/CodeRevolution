#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
void merge(int arr[],int l1,int r1,int l2,int r2,unordered_map<int,int> &hm){

	int n1=r1-l1+1;
	int n2=r2-l2+1;

	int *L=(int*)calloc(n1,sizeof(int));
	int *R=(int*)calloc(n2,sizeof(int));

	int i,j,k;
	k=0;
	for(i=0;i<n1;i++)
		L[i]=arr[l1+i];
	k=0;
	for(j=0;j<n2;j++)
		R[j]=arr[l2+j];
	
	i=0;j=0;
	k=l1;
	int c=0;
	while(i<n1&&j<n2){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			hm[arr[k]]=hm[arr[k]]+c;
			k++;
			i++;
		}
		else{
			arr[k]=R[j];
			k++;
			j++;
			c++;
		}
	}
	while(i<n1){
		hm[L[i]]+=c;
		arr[k++]=L[i++];
	}
	while(j<n2){
		arr[k++]=R[j++];
	}
	free(L);
	free(R);
}
void mergeSort(int arr[],int l,int r,unordered_map<int,int> &hm){
	if(l>=r)
		return;
	int m=(l+r)/2;
	mergeSort(arr,l,m,hm);
	mergeSort(arr,m+1,r,hm);
	merge(arr,l,m,m+1,r,hm);
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	int arr[1000];
	int dup[1000];
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>arr[i];
			dup[i]=arr[i];
		}
		unordered_map<int,int> hm;
		mergeSort(dup,0,N-1,hm);
		for(int i=0;i<N;i++){
			hm[arr[i]]=N-i-1-hm[arr[i]];
			cout<<hm[arr[i]]<<" ";
		}
		cout<<endl;
	}
}