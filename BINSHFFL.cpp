#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(false);
	long long int T,A,B,s,fs,oA,ofs,temp,one;
	cin>>T;
	while(T--){
		cin>>A>>B;
		if(A==B){
			cout<<0<<endl;
			continue;
		}
		if(B==0){
			cout<<-1<<endl;
			continue;
		}
		fs=B-1;
		if(fs==0&&A!=0){
			cout<<"-1\n";
			continue;
		}
		ofs=oA=0;
		one=1;
		//cout<<(one<<54)<<endl;
		for(int i=0;i<=62;i++){
			//cout<<"i = "<<i<<endl;
			temp=one<<i;
			if(temp&fs){
				//cout<<"nfs = "<<temp<<endl;
				ofs++;
			}
			if(temp&A){
				//cout<<"nA = "<<temp<<endl;
				oA++;
			}
		}
		//cout<<"oA = "<<oA<<" ofs = "<<ofs<<endl;
		if(oA>ofs){
			cout<<"2\n";
		}
		else{
			s=ofs-oA;
			s++;
			cout<<s<<endl;
		}
	}
}