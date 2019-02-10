int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    // unordered_map<int,int> hm;
    // for(int i=0;i<A.size();i++){
    //     if(A[i]<0){
    //         continue;
    //     }
    //     if(hm.find(A[i])==hm.end()){
    //         hm[A[i]]=1;
    //     }
    //     else{
    //         hm[A[i]]++;
    //     }
    // }
    for(int i=0;i<A.size();i++){
        if(A[i]<0){
            continue;
        }
        if(A[i]==(A.size()-i-1)){
            if((i<A.size()-1&&A[i+1]!=A[i])||(i==A.size()-1))
                return 1;
        }
    }
    return -1;
}
