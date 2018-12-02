#include <bits/stdc++.h>
using namespace std;
#define MAX 100
vector<string> printPath(int m[MAX][MAX], int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	
	int m[100][100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>m[i][j];
		}
	}
	
	vector<string> res = printPath(m,n);
	for(int i=0;i<res.size();i++)
	cout<<res[i]<<" ";
	cout<<endl;
}
	return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The function returns a sorted array of strings which represents
the directions mouse will take to reach the destination.
You are required to complete the below method. */
inline bool inRange(int x,int y,int n){
	//cout<<"here4\n";
	if(0<=x&&x<n&&0<=y&&y<n)
		return true;
	return false;
}
inline void getPaths(int m[MAX][MAX],int n,int x,int y,vector<string> &res,string path){
	if(x<0||y<0||x>=n||y>=n||m[x][y]==0||m[x][y]==2)
		return;
	else if(x==n-1&&y==n-1)
		res.push_back(path);
	else{
		m[x][y]=2;
		getPaths(m,n,x-1,y,res,path+'U');
		getPaths(m,n,x,y-1,res,path+'L');
		getPaths(m,n,x+1,y,res,path+'D');
		getPaths(m,n,x,y+1,res,path+'R');
		m[x][y]=1;
	}
}
vector<string> printPath(int m[MAX][MAX], int n)
{
    //Your code here
    vector<string> res;
    string path="";
    //cout<<"here1\n";
    getPaths(m,n,0,0,res,path);
    sort(res.begin(),res.end());
    return res;
}