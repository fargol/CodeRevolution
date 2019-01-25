int Solution::minCut(string A) {
    int N=A.length();
    int DP[N][N];
    bool P[N][N];
    for(int i=0;i<N;i++){
        DP[i][i]=0;
        P[i][i]=true;
    }
    for(int l=2;l<=N;l++){
        for(int i=0;i<N-l+1;i++){
            int j=i+l-1;
            if(l==2){
                P[i][j]=(A[i]==A[j]);
            }
            else{
                if(A[i]==A[j]){
                    P[i][j]=P[i+1][j-1];
                }
                else{
                    P[i][j]=false;
                }
            }
            if(P[i][j]){
                DP[i][j]=0;
            }
            else{
                DP[i][j]=INT_MAX;
                for(int k=i;k<j;k++){
                    DP[i][j]=min(DP[i][k]+DP[k+1][j]+1,DP[i][j]);
                }
            }
        }
    }
    return DP[0][N-1];
}