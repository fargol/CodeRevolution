int Solution::minPathSum(vector<vector<int> > &A) {
    int N=A.size(),M=A[0].size();
    int dp[N][M];
    dp[0][0]=A[0][0];
    for(int i=1;i<N;i++){
        dp[i][0]=dp[i-1][0]+A[i][0];
    }
    for(int i=1;i<M;i++){
        dp[0][i]=dp[0][i-1]+A[0][i];
    }
    for(int i=1;i<N;i++){
        for(int j=1;j<M;j++){
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+A[i][j];
        }
    }
    return dp[N-1][M-1];
}