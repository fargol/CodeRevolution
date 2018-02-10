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
			//cout<<"target:"<<target<<endl;
			for(int i=N;i>=1&&target>0;i--){
				temp=target-i;
				if(temp>=0&&i!=x){
					target-=i;
					v[i]='0';
				}
				if(target<i&&target>0){
					if(target!=x){
						v[target]='0';
						target-=target;
					}
					else{
						target+=i;
						target-=i-1;
						target-=x+1;
						v[i-1]=v[x+1]='0';
						v[i]='\0';
					}
					break;
				}
			}
			if(target==0){
				//cout<<"here\n";
				for(int i=1;i<=N;i++){
					if(v[i]!='0'&&v[i]!='2'){
						target+=i;
						v[i]='1';
					}
				}
				//cout<<"here target:"<<target<<endl;
				if(target==sum>>1){
					for(int i=1;i<=N;i++)
						cout<<v[i];
					cout<<endl;
				}
				else
					cout<<"impossible\n";
			}
			else
				cout<<"impossible\n";
			free(v);
		}
	}
} 