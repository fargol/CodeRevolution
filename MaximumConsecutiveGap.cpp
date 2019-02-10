int Solution::maximumGap(const vector<int> &A) {
    int MAX=INT_MIN,MIN=INT_MAX,N=A.size();
    if(N==1||N==0){
        return 0;
    }
    for(int i=0;i<N;i++){
        MAX=max(MAX,A[i]);
        MIN=min(MIN,A[i]);
    }
    int gap=(MAX-MIN)/N;
    if(gap==0){
        return 0;
    }
    vector<pair<int,int> > buckets(N+1,{INT_MAX,INT_MIN});
    for(int i=0;i<N;i++){
        int j=(A[i]-MIN)/gap;
        buckets[j].first=min(buckets[j].first,A[i]);
        buckets[j].second=max(buckets[j].second,A[i]);
    }
    int res=INT_MIN;
    for(int i=0;i<N+1;i++){
        if(buckets[i].first!=INT_MAX&&buckets[i].second!=INT_MIN){
            res=max(res,buckets[i].first-prev);
            prev=buckets[i].second;
        }
    }
    return res;
}
