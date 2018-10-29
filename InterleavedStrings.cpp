#include <bits/stdc++.h>
using namespace std;
bool isInterleave(string A, string B, string C);
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string a,b,c;
        cin>>a;
        cin>>b;
        cin>>c;
        cout<<isInterleave(a,b,c)<<endl;
    }
    // your code goes here
    return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method */
bool isInterleave(string A, string B, string C) 
{
    //Your code here
    if(C.length()!=A.length()+B.length())
        return false;
    bool dp[A.length()+1][B.length()+1];
    for(int i=0;i<=A.length();i++){
        for(int j=0;j<=B.length();j++){
            dp[i][j]=false;
            if(i==0&&j==0)
                dp[i][j]=true;
            else if(i==0&&C[i+j-1]==B[j-1])
                dp[i][j]=dp[i][j-1];
            else if(j==0&&C[i-1]==A[i-1])
                dp[i][j]=dp[i-1][j];
            else if(A[i-1]==C[i+j-1]&&B[j-1]!=C[i+j-1])
                dp[i][j]=dp[i-1][j];
            else if(A[i-1]!=C[i+j-1]&&B[j-1]==C[i+j-1])
                dp[i][j]=dp[i][j-1];
            else if(A[i-1]==C[i+j-1]&&B[j-1]==C[i+j-1])
                dp[i][j]=(dp[i-1][j]|dp[i][j-1]);
        }
    }
    return dp[A.length()][B.length()];
}
