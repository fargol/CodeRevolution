#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
 
int main(){
	int T,N,x;
	long long int sum,target,temp;
	char* v;
	cin>>T;
	while(T--){
		cin>>x>>N;
		sum=0;
		if(N==2||N==3){
			cout<<"impossible\n";
			continue;
		}
		//sum=pow(N,2);
		for(int i=1;i<=N;i++)
			sum+=i;
		//sum+=N;
		//sum>>=1;
		sum-=x;
		if(sum&1)
			cout<<"impossible\n";
		else{
			v=(char*)calloc(N+1,sizeof(char));
			v[x]='2';
			target=sum>>1;
			int i=N;
			while(target>=i){
				if(i!=x){
					target-=i;
					v[i]='0';
				}
				i--;
			}
			
				if(target!=x){
					v[target]='0';
					target-=target;
				}
				else{
					target+=i+1;
					target-=i;
					target-=x+1;
					v[i]=v[x+1]='0';
					v[i+1]='\0';
				}
				for(int i=1;i<=N;i++){
					if(v[i]=='\0')
						cout<<1;
					else
						cout<<v[i];
				}
				cout<<endl;
			free(v);
		}
	}
} 