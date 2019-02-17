string Solution::longestCommonPrefix(vector<string> &A){
    string res="";
    char t;
    int i=0;
    while(true){
        if(i<A[0].size()){
            t=A[0][i];
        }
        else{
            return res;
        }
        for(int j=1;j<A.size();j++){
            if(i>=A[j].size()){
                return res;
            }
            if(A[j][i]!=t){
                return res;
            }
        }
        res+=t;
        i++;
    }
    return res;
}
