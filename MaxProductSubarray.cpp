int Solution::maxProduct(const vector<int> &A) {
    int N=A.size();
    vector<pair<int,int> > dp(N);
    if(A[0]<0){
        dp[0].second=A[0];
        dp[0].first=0;
    }
    else if(A[0]==0){
        dp[0].first=dp[0].second;
    }
    else{
        dp[0].first=A[0];
        dp[0].second=0;
    }
    int maxprod=max(dp[0].first,dp[0].second);
    for(int i=1;i<N;i++){
        if(A[i]==0){
            dp[i].first=dp[i].second=0;
        }
        else if(A[i]<0){
            dp[i].first=max(0,dp[i-1].second*A[i]);
            dp[i].second=min(A[i],dp[i-1].first*A[i]);
        }
        else{
            dp[i].first=max(A[i],dp[i-1].first*A[i]);
            dp[i].second=min(A[i],dp[i-1].second*A[i]);
        }
        maxprod=max(maxprod,max(dp[i].first,dp[i].second));
    }
    return maxprod;
}
