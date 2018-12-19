#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define   long long
//#define   unsigned long long
#define M 1000000007
inline void solve(    unsigned int N,vector<    unsigned int> &a,    unsigned int offset){
	    unsigned int x,y,z,QS=0;
	vector<    unsigned int> Q(N+1);
	for(    unsigned int i=1;i<=N;i++){
		x=i;
		x+=offset;
		y=(i+1)%N;
		if(y==0)
			y=N;
		y+=offset;
		z=(i+2)%N;
		if(z==0)
			z=N;
		z+=offset;
		cout<<"1 "<<x<<" "<<y<<" "<<z<<endl;
		cin>>Q[i];
		QS^=Q[i];
	}
	if(N%3==1){
		    unsigned int l=1;
		    unsigned int k=N/3,id;
		a[offset+N]=QS;
		for(    unsigned int j=1;j<=k;j++){
			id=(l+(j-1)*3)%N;
			if(id==0)
				id=N;
			a[N+offset]^=Q[id];
		}
		l++;
		for(    unsigned int i=1;i<=N-1;i++){
			a[i+offset]=QS;
			k=N/3;
			for(    unsigned int j=1;j<=k;j++){
				id=(l+(j-1)*3)%N;
				if(id==0)
					id=N;
				a[i+offset]^=Q[id];
			}
			l++;
		}
	}
	else if(N%3==2){
		    unsigned int l=1;
		for(    unsigned int i=1;i<=N;i++){
			a[i+offset]=QS;
			    unsigned int k=N/3,id;
			for(    unsigned int j=1;j<=k;j++){
				id=(l+(j-1)*3)%N;
				if(id==0)
					id=N;
				a[i+offset]^=Q[id];
			}
			id=(id+3)%N;
			if(id==0)
				id=N;
			a[i+offset]^=Q[id];
			l++;
		}
	}
}
int main(){
	ios::sync_with_stdio(true);
	    unsigned int T,N;
	cin>>T;
	vector<unsigned int> a(50010);
	while(T--){
		cin>>N;
		int r;
		cout<<"1 "<<1<<" "<<1<<" "<<1<<endl;
		cin>>r;
		if(r!=-1){
			if(N%4==0){
				unsigned int Q[6],Qs;
				unsigned int i=1;
				while(i<=N-3){
					cout<<"1 "<<i<<" "<<i+1<<" "<<i+2<<endl;
					cin>>Q[1];
					if(Q[1]==-1)
						return 0;
					cout<<"1 "<<i+1<<" "<<i+2<<" "<<i+3<<endl;
					cin>>Q[2];
					if(Q[2]==-1)
						return 0;
					cout<<"1 "<<i+2<<" "<<i+3<<" "<<i<<endl;
					cin>>Q[3];
					if(Q[3]==-1)
						return 0;
					cout<<"1 "<<i+3<<" "<<i<<" "<<i+1<<endl;
					cin>>Q[4];
					if(Q[4]==-1)
						return 0;
					Qs=0;
					for(unsigned int j=1;j<=4;j++){
						Qs^=Q[j];
					}
					a[i]=Q[2]^Qs;
					a[i+1]=Q[3]^Qs;
					a[i+2]=Q[4]^Qs;
					a[i+3]=Q[1]^Qs;
					i+=4;
				}
			}
		}
		else if(N%3==0){
			    unsigned int n=N;
			while(n%3==0)
				n/=3;
			    unsigned int offset=0;
			for(    unsigned int i=1;i<=N;i+=n){
				solve(n,a,offset);
				offset+=n;
			}
		}
		else{
			solve(N,a,0);
		}
		cout<<"2 ";
		for(    unsigned int i=1;i<=N;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		    int res;
		cin>>res;
	}
}