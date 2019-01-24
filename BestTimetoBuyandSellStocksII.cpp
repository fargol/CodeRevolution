int Solution::maxProfit(const vector<int> &A) {
    int profit=0,bp=-1,sp=-1,N=A.size();
    if(N==0){
        return 0;
    }
    if(A[0]<A[1]){
        bp=A[0];
    }
    for(int i=1;i<N-1;i++){
        if(A[i-1]<=A[i]&&A[i]>=A[i+1]&&bp!=-1){
            sp=A[i];
            profit+=(sp-bp);
            bp=-1;
            sp=-1;
        }
        if(A[i-1]>=A[i]&&A[i]<=A[i+1]){
            bp=A[i];
        }
    }
    if(A[N-2]<=A[N-1]&&bp!=-1){
        sp=A[N-1];
        profit+=(sp-bp);
        bp=-1;
        sp=-1;
    }
    return profit;
}
