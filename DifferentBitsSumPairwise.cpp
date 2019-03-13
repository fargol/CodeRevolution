int Solution::cntBits(vector<int> &A) {
    long long int ans=0;
    for(int i=0;i<31;i++){
        int c=0;
        for(int j=0;j<A.size();j++){
            if(A[j]>>i&1){
                c++;
            }
        }
        long long int res=c*(A.size()-c);
        res<<=1;
        ans+=res;
        ans%=1000000007;
    }
    return ans;
}
