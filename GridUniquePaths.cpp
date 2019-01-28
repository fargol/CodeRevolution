int Solution::uniquePaths(int A, int B) {
    vector<vector<int> > dp(A,vector<int>(B));
    dp[0][0]=1;
    for(int i=1;i<A;i++){
        dp[i][0]=dp[i-1][0];
    }
    for(int j=1;j<B;j++){
        dp[0][j]=dp[0][j-1];
    }
    for(int i=1;i<A;i++){
        for(int j=1;j<B;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[A-1][B-1];
}
