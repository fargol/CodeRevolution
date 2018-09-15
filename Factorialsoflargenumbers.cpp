#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define M 1000000007;
typedef pair<int, int> ii; typedef vector<ii> vii;
void multiply(int res[],int x,int &res_size){
	int i,carry=0,prod;
	for(i=0;i<res_size;i++){
		prod=res[i]*x+carry;
		res[i]=prod%10;
		prod/=10;
		carry=prod;
	}
	while(carry>0){
		res[i]=carry%10;
		carry/=10;
		i++;
	}
	res_size=i;
}
int findFactorial(int res[],int N,int res_size){
	for(int i=2;i<N;i++)
		multiply(res,i,res_size);
	return res_size;
}
void printRes(int res[],int res_size){
	for(int i=res_size-1;i>=0;i--)
		cout<<res[i];
	cout<<endl;
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	long long int T,N,fac,count;
	cin>>T;
	while(T--){
		cin>>N;
		int res[9999];
		int temp=N;
		int i=0;
		while(temp>0){
			res[i]=temp%10;
			temp/=10;
			i++;
		}
		int res_size=i;
		//printRes(res,res_size);
		res_size=findFactorial(res,N,res_size);
		printRes(res,res_size);
	}
}