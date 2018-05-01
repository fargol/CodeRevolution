#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int main(){
	int T,N,S;
	cin>>T;
	while(T--){
		cin>>N>>S;
		//scanf("%d %d",&N,&S);
		//cout<<"N = "<<N<<" S = "<<S<<endl;
		vector<int> arr(N+1,0);
		vector<int> sum(N+1,0);
		//cout<<"sum[0] = "<<sum[0]<<endl;
		cin>>arr[1];
		//cout<<"arr[0] = "<<arr[0]<<endl;
		sum[1]=arr[1];
		int j=0;
		int idx1;
		int diff;
		int idx2=idx1=0;
		for(int i=2;i<=N;i++){
			cin>>arr[i];
			sum[i]=arr[i]+sum[i-1];
		}
		for(int i=1;i<=N;i++){
			diff=sum[i]-sum[j];
			//cout<<"DIFF = "<<diff<<endl;
			while(diff>S){
				//cout<<"here\n";
				j++;
				diff=sum[i]-sum[j];
			}
			//cout<<"\ni = "<<i<<" j = "<<j<<" Sum[i] = "<<sum[i]<<" Sum[j] = "<<sum[j]<<endl;
			//cout<<"\nDIFF = "<<diff<<endl;
			//printf("%d : %d\n",i,sum[i]);
			if(diff==S){
				idx1=j+1;
				idx2=i;
				break;
			}
		}

		if(idx1!=0&&idx2!=0){
			cout<<idx1<<" "<<idx2<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
}