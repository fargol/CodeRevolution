int Solution::lis(const vector<int> &A) {
    int N=A.size();
    vector<int> dp(N);
    dp[0]=1;
    int res=1;
    for(int i=1;i<N;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(A[j]<A[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        res=max(dp[i],res);
    }
    return res;
}
