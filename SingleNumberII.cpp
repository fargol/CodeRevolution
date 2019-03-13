int Solution::singleNumber(const vector<int> &A) {
    int X=0;
    for(int i=31;i>=0;i--){
        int c=0;
        for(int j=0;j<A.size();j++){
            if((A[j]>>i)&1){
                c++;
            }
        }
        X<<=1;
        if(c%3==1){
            X+=1;
        }
    }
    return X;
}
