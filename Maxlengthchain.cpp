#include <bits/stdc++.h>
using namespace std;
struct val{
	int first;
	int second;
};
int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
/*You are required to complete this method*/
bool cmp(const val a,const val b){
	return a.second<b.second;
}
int maxChainLen(struct val p[],int n)
{
//Your code here
	sort(p,p+n,cmp);
	int len=1;
	val curr;
	curr=p[0];
	for(int i=1;i<n;i++){
		if(curr.second<p[i].first){
			len++;
			curr=p[i];
		}
	}
	return len;
}