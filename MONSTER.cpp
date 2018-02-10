#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	int n,q,x,y,count,res,res2;
	cin>>n;
	vector<int> arr(n);
	for(int &i:arr)
		cin>>i;
	cin>>q;
	count=n;
	while(q--){
		cin>>x>>y;
		res=1;
		for(int i=0;i<32;i++){
			if(x&pow(2,i)!=0)
				res<<=1;
		}
		count-=res;
		/*for(int k=0;k<n;k++){
			res=k&x;
			if(res==k&&arr[k]>0){
				arr[k]-=y;
				if(arr[k]<=0)
					count--;
			}
		}*/
		cout<<count<<endl;
	}
}