int Solution::minDistance(string A, string B) {
    int a=A.length(),b=B.length();
    vector<vector<int> > dp(a+1,vector<int>(b+1,0));
    dp[0][0]=0;
    for(int i=1;i<=a;i++){
        dp[i][0]=i;
    }
    for(int j=1;j<=b;j++){
        dp[0][j]=j;
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(A[i-1]==B[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
            }
        }
    }
    return dp[a][b];
}