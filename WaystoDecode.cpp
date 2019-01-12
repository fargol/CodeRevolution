int Solution::numDecodings(string A) {
    vector<int> ways(A.size());
    if(A[0]=='0'){
        return 0;
    }
    ways[0]=1;
    ways[1]=ways[0];
    if(A[0]=='1'&&A[1]>'0'){
        ways[1]++;
    }
    else if(A[0]=='2'&&'1'<=A[1]&&A[1]<='6'){
        ways[1]++;
    }
    for(int i=2;i<A.size();i++){
        if(A[i]=='0'&&(A[i-1]>='3'||A[i-1]=='0')){
            return 0;
        }
        if(A[i]=='0'){
            ways[i]=0;
            if('1'<=A[i-1]&&A[i-1]<='2'){
                ways[i]+=ways[i-2];
            }
        }
        else{
            ways[i]=ways[i-1];
            if(A[i-1]=='1'&&A[i]>'0'){
                ways[i]+=ways[i-2];
            }
            else if(A[i-1]=='2'&&'1'<=A[i]&&A[i]<='6'){
                ways[i]+=ways[i-2];
            }
        }
    }
    return ways[A.size()-1];
}