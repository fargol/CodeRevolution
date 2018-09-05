#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int n,m,a[5000],b[5000],T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int j=0;j<m;j++)
			cin>>b[j];
		int sumA=0,sumB=0;
		bool a_b[n]={false};
		bool b_b[m]={false};
		sort(a,a+n);
		sort(b,b+m);
		int i=0,j=0;
		int max_sum=0;
		while(i<n&&j<m){
			if(a[i]!=b[j]){
				if(!a_b[i]){
					sumA+=a[i];
					a_b[i]=true;
				}
				if(!b_b[j]){
					sumB+=b[j];
					b_b[j]=true;
				}
				if(a[i]<b[j])
					i++;
				else
					j++;
			}
			else{
				max_sum+=max(sumA,sumB);
				sumB=sumA=0;
				int ii=i,jj=j;
				int c=a[i];
				while(ii<n&&a[ii]==c){
					if(!a_b[ii]){
						sumA+=a[ii];
						a_b[ii]=true;
					}
					ii++;
				}
				while(jj<m&&b[jj]==c){
					if(!b_b[jj]){
						b_b[jj]=true;
						sumB+=b[jj];
					}
					jj++;
				}
				max_sum+=(sumA+sumB-a[i]);
				i=ii;
				j=jj;
				/*cout<<"max_sum = "<<max_sum<<endl;
				cout<<"sumA = "<<sumA<<endl;
				cout<<"sumB = "<<sumB<<endl;
				cout<<"i = "<<i<<endl;
				cout<<"j = "<<j<<endl;*/
			}
		}
		if(i<n){
			for(int k=i+1;k<n;k++){
				sumA+=a[k];
				a_b[k]=true;
			}
		}
		if(j<m){
			for(int k=j+1;k<m;k++){
				b_b[k]=true;
				sumB+=b[k];
			}
		}
		if(sumA<sumB){
			max_sum+=sumB;
		}
		else{
			max_sum+=sumA;
		}
		cout<<max_sum<<endl;
	}
}