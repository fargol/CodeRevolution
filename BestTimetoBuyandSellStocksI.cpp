int Solution::maxProfit(const vector<int> &A) {
    int N=A.size(),profit=0,bp=-1,sp=-1;
    if(N==0||N==1){
        return 0;
    }
    vector<int> ll(N),hr(N);
    ll[0]=A[0];
    for(int i=1;i<N;i++){
        ll[i]=min(ll[i-1],A[i]);
    }
    hr[N-1]=A[N-1];
    for(int i=N-2;i>=0;i--){
        hr[i]=max(hr[i+1],A[i]);
    }
    for(int i=0;i<N-1;i++){
        profit=max(hr[i+1]-ll[i],profit);
    }
    return profit;
}
