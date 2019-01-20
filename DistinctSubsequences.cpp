int Solution::numDistinct(string S, string T) {
    int n=S.length(),m=T.length();
    if(n<m){
        return 0;
    }
    vector<vector<int> > dp(m+1,vector<int>(n+1,0));
    for(int k=0;k<=n;k++){
        dp[0][k]=1;
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=m;i++){
            if(T[i-1]==S[j-1]){
                dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
            }
            else{
                dp[i][j]=dp[i][j-1];
            }
        }
    }   
    return dp[m][n];
}