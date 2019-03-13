int Solution::singleNumber(const vector<int> &A) {
    int X=0;
    for(int i=0;i<A.size();i++){
        X^=A[i];
    }
    return X;
}
