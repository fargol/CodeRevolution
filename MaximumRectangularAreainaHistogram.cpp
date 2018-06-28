#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		vector<int> arr(N);
		for(int &i:arr)
			cin>>i;
		//vector<int> minimum(N);
		//minimum[0]=arr[0];
		/*for(int i=1;i<N;i++){
			if(arr[i]<minimum[i-1])
				minimum[i]=arr[i];
			else
				minimum[i]=minimum[i-1];
		}*/
		int max=INT_MIN;
		int l,b;
		for(int i=0;i<N;i++){
			for(int j=i;j<N;j++){
				l=j-i+1;
				int min=INT_MAX;
				for(int k=i;k<=j;k++){
					if(min>arr[k])
						min=arr[k];
				}
				if(max<min*l)
					max=min*l;
			}
		}
		cout<<max<<endl;
	}
}