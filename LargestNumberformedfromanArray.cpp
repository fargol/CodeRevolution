#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef pair<int, int> ii; typedef vector<ii> vii;
bool cmp(const string X,const string Y){
	string XY=X+Y;
	string YX=Y+X;
	int XYi=stoi(XY);
	int YXi=stoi(YX);
	return (XYi>YXi);
}
int main(){
	//vector<vii> AdjList;
	//vector< pair<int, ii> > EdgeList;
	ios::sync_with_stdio(true);
	int T,N;
	vector<string> arr(100);
	string largest_num;
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>arr[i];
		sort(arr.begin(),arr.begin()+N,cmp);
		largest_num="";
		for(int i=0;i<N;i++)
			largest_num+=arr[i];
		cout<<largest_num<<endl;
	}
}