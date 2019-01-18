int Solution::jump(vector<int> &A) {
    int N=A.size();
    if(N<=0){
        return -1;
    }
    if(A[0]==0&&N==1){
        return 0;
    }
    if(A[0]==0){
        return -1;
    }
    int maxReach=A[0],currReach=A[0],steps=1;
    for(int i=0;i<=maxReach;i++){
        if(i>=N-1){
            return steps;
        }
        currReach=max(currReach,i+A[i]);
        if(i==maxReach){
            if(currReach<=i){
                return -1;
            }
            maxReach=currReach;
            steps++;
        }
    }
    return -1;
}
