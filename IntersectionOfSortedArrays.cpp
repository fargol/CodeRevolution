vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int i=0,j=0;
    vector<int> res;
    while(i<A.size()&&j<B.size()){
        if(A[i]==B[j]){
            res.push_back(A[i]);
            i++;
            j++;
        }
        if(A[i]<B[j]){
            i++;
        }
        if(B[j]<A[i]){
            j++;
        }
    }
    return res;
}
