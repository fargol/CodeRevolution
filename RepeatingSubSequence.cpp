int Solution::anytwo(string A) {
    int N=A.length();
    vector<vector<int> > dp(N+1,vector<int>(N+1,0));
    for(int i=1;i<N+1;i++){
        for(int j=1;j<N+1;j++){
            dp[i][j]=0;
            if(i!=j){
                if(A[i-1]==A[j-1]){
                    dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j]);
                }
                else{
                    dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i][j]));
                }
            }
        }
    }
    for(int i=0;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            if(dp[i][j]>1){
                return 1;
            }
        }
    }
    return 0;
}