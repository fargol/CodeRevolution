int Solution::canJump(vector<int> &A) {
    int N=A.size();
    vector<bool> dp(N,false);
    dp[N-1]=true;
    for(int i=N-2;i>=0;i--){
        for(int j=i;j<=i+A[i]&&j<N;j++){
            dp[i]=dp[i]|dp[j];
        }
    }
    return dp[0];
}