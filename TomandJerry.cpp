#include <bits/stdc++.h>
using namespace std;
int main() {
	//code
	int T,N;
	vector<int> dpT(100001);vector<int> dpJ(100001);
	dpT[1]=0;dpJ[1]=1;
	//0-> Jerry wins
	//1-> Tom wins
	cin>>T;
	while(T--){
	   cin>>N;
		for(int i=2;i<=N;i++){
			dpT[i]=-1;
			dpJ[i]=-1;
		    for(int j=1;j*j<i;j++){
		        if(i%j==0){
		            //cout<<"i-j = "<<i-j<<" "<<dpT[i-j]<<": "<<dpJ[i-1]<<endl;
		            if(dpJ[i-j]==1){
		                dpT[i]=1;
		                //cout<<"here = "<<dpT[i]<<" && i = "<<i<<endl;
		            }
		            else{
		                //cout<<"er"<<endl;
		                if(dpT[i]!=1)
		                	dpT[i]=0;
		            }
		           	if(dpT[i-j]==1){
		           		if(dpJ[i]!=0)
		                	dpJ[i]=1;
		           	}
		           	else{
		                dpJ[i]=0;
		           	}
		            int k=i/j;
		            //cout<<" k = "<<k<<endl;
		            if(k!=j&&k<i){
		            	//cout<<"inside\n";
			            if(dpJ[i-k]==1)
			                dpT[i]=1;
			            else{
			            	if(dpT[i]!=1)
			                	dpT[i]=0;
			            }
			           	if(dpT[i-k]==1){
			           		if(dpJ[i]!=0)
			                	dpJ[i]=1;
			           	}
			           	else
			                dpJ[i]=0;
			        }
		        }
		    }
		}
		cout<<dpT[N]<<endl;
	}
	return 0;
}