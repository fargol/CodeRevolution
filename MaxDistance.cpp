int Solution::maximumGap(const vector<int> &A) {
    int N=A.size();
    vector<pair<int,int> > arr(N);
    for(int i=0;i<N;i++){
        arr[i].first=A[i];
        arr[i].second=i;
    }
    sort(arr.begin(),arr.end());
    vector<int> maxj(N);
    maxj[N-1]=arr[N-1].second;
    for(int i=N-2;i>=0;i--){
        maxj[i]=max(arr[i].second,maxj[i+1]);
    }
    int ans=0;
    for(int i=0;i<N;i++){
        ans=max(ans,maxj[i]-arr[i].second);
    }
    return ans;
}
