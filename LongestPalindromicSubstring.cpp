// A C++ program to implement Manacher’s Algorithm
#include<bits/stdc++.h>
using namespace std;
void findLongestPalindromicString(char text[]);
// driver Program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char str[100];
        cin>>str;
        findLongestPalindromicString(str);
    }
	return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

// your task is to complete this function
void findLongestPalindromicString(char text[])
{
 // code here
	int len=strlen(text);
	bool dp[len][len];
	memset(dp,false,sizeof(dp));
	for(int i=0;i<len;i++)
		dp[i][i]=true;
	int maxlen=1;
	int x=0,y=0;
	for(int i=0;i<len-1;i++){
		if(text[i]==text[i+1]){
			dp[i][i+1]=true;
			if(maxlen<2){
				maxlen=2;
				x=i;
				y=i+1;
			}
		}
	}
	for(int l=3;l<=len;l++){
		for(int i=0;i<len-l+1;i++){
			int j=i+l-1;
			if(dp[i+1][j-1]&&text[i]==text[j]){
				dp[i][j]=true;
				if(maxlen<l){
					maxlen=l;
					x=i;
					y=j;
				}
			}
		}
	}
	for(int i=x;i<=y;i++)
		cout<<text[i];
	cout<<endl;
}