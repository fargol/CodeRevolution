#include<bits/stdc++.h>
using namespace std;
int wildCard(string pattern,string str);
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'');
           cin>>text;
           cout<<wildCard(pat,text)<<endl;
   }
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method*/
int wildCard(string pattern,string str)
{
	int lp=pattern.length(),lstr=str.length();
	int dp[lp+1][lstr+1];
	dp[0][0]=1;
	for(int i=1;i<=lstr;i++){
		dp[0][i]=0;
	}
	for(int j=1;j<=lp;j++){
		if(pattern[j-1]=='*')
			dp[j][0]=dp[j-1][0];
		else
			dp[j][0]=0;
	}
	for(int i=1;i<=lp;i++){
		for(int j=1;j<=lstr;j++){
			if(pattern[i-1]=='*')
				dp[i][j]=dp[i][j-1]||dp[i-1][j];
			else if(pattern[i-1]=='?'||pattern[i-1]==str[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=0;
		}
	}
	return dp[lp][lstr];
}
