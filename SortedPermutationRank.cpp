#define M 1000003
int Solution::findRank(string A){
    int res=0;
    //transform(A.begin(), A.end(), A.begin(), ::tolower); 
    int alpha[123]={0};
    for(int i=0;i<A.length();i++){
        alpha[A[i]-'a']++;
    }
    int cum[123];
    cum[0]=alpha[0];
    for(int i=1;i<26;i++){
        cum[i]=cum[i-1]+alpha[i];
    }
    int N=A.size();
    int fac[N+1];
    fac[0]=1;
    for(int i=1;i<=N;i++){
        fac[i]=(i*fac[i-1])%M;
    }
    int used[123]={0};
    for(int i=0;i<N;i++){
        used[A[i]-'A']=1;
    }
    for(int i=0;i<N;i++){
        int c=0;
        for(int j=A[i]-'A'-1;j>=0;j--){
            if(used[j]==1)
                c++;
        }
        res=(res+(c*fac[N-i-1])%M)%M;
        used[A[i]-'A']=2;
    }
    res=(res+1)%M;
    return res;
}
