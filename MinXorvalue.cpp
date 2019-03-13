int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(),A.end());
    int minXor=INT_MAX;
    for(int i=0;i<A.size()-1;i++){
        minXor=min(minXor,A[i]^A[i+1]);
    }
    return minXor;
}
