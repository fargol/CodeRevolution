int Solution::solve(const vector<int> &A) {
    int N=A.size();
    if(N<3){
        return N;
    }
    vector<vector<int> > dp(N,vector<int>(N,0));
    unordered_map<int,int> hm;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            dp[i][j]=2;
            int diff=A[j]-A[i];
            int x=2*A[i]-A[j];
            if(hm.count(x)==0){
                continue;
            }
            else{
                dp[i][j]=max(dp[i][j],dp[hm[x]][i]+1);
            }
        }
        hm[A[i]]=i;
    }
    int ans=2;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}
