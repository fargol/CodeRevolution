int Solution::maxSubArray(const vector<int> &A) {
    int max_so_far=0;
    int maxsum=INT_MIN;
    for(int i=0;i<A.size();i++){
        max_so_far+=A[i];
        maxsum=max(max_so_far,maxsum);
        if(max_so_far<0){
            max_so_far=0;
        }
    }
    return maxsum;
}
