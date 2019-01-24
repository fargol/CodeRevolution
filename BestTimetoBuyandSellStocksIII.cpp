int Solution::maxProfit(const vector<int> &A) {
    int N=A.size();
    if(N==0||N==1){
        return 0;
    }
    if(N==2){
        return max(0,A[1]-A[0]);
    }
    int K=2;
    int dp[K+1][N];
    for(int i=0;i<N;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<3;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<3;i++){
        dp[i][1]=0;
    }
    int maxp=0;
    for(int i=1;i<3;i++){
        int tmpMax = dp[i-1][0]-A[0];
        for(int j=1;j<N;j++){
            dp[i][j]=max(dp[i][j-1],A[j]+tmpMax);
            tmpMax = max(tmpMax, dp[i-1][j]-A[j]);
            maxp=max(maxp,dp[i][j]);
        }
    }
    return maxp;
}
