int Solution::chordCnt(int N){
    if(N==0){
        return 1;
    }
    else if(N==1){
        return 1;
    }
    else if(N==2){
        return 2;
    }
    vector<long long int> dp(N+1,0);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<N+1;i++){
        dp[i]=0;
        for(int j=0;j<i;j++){
            dp[i]+=(dp[j]*dp[i-j-1]);
            dp[i]%=1000000007;
        }
    }
    return dp[N]%1000000007;
}
