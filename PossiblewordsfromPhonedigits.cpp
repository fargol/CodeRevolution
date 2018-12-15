#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define M 1000000007
void getStrings(vector<int> &arr,vector<vector<char> > &alphanum, int idx,string res){
	if(idx==arr.size()){
		cout<<res<<" ";
		return;
	}
	for(int i=0;i<alphanum[arr[idx]].size();i++){
		string str=res;
		str+=alphanum[arr[idx]][i]+32;
		getStrings(arr,alphanum,idx+1,str);
	}
}
int main(){
	ios::sync_with_stdio(true);
	vector<vector<char> > alphanum(10);
	alphanum[2]=vector<char>(3);
	alphanum[2][0]='A';alphanum[2][1]='B';alphanum[2][2]='C';
	alphanum[3]=vector<char>(3);
	alphanum[3][0]='D';alphanum[3][1]='E';alphanum[3][2]='F';
	alphanum[4]=vector<char>(3);
	alphanum[4][0]='G';alphanum[4][1]='H';alphanum[4][2]='I';
	alphanum[5]=vector<char>(3);
	alphanum[5][0]='J';alphanum[5][1]='K';alphanum[5][2]='L';
	alphanum[6]=vector<char>(3);
	alphanum[6][0]='M';alphanum[6][1]='N';alphanum[6][2]='O';
	alphanum[7]=vector<char>(4);
	alphanum[7][0]='P';alphanum[7][1]='Q';alphanum[7][2]='R';alphanum[7][3]='S';
	alphanum[8]=vector<char>(3);
	alphanum[8][0]='T';alphanum[8][1]='U';alphanum[8][2]='V';
	alphanum[9]=vector<char>(4);
	alphanum[9][0]='W';alphanum[9][1]='X';alphanum[9][2]='Y';alphanum[9][3]='Z';
	
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		vector<int> arr(N);
		for(int &i:arr)
			cin>>i;
		string res="";
		getStrings(arr,alphanum,0,res);
		cout<<endl;
	}
}