int Solution::solve(vector<vector<int> > &A) {
    int N=A.size(),M=A[0].size();
    vector<vector<int> > C(N,vector<int>(M));
    for(int j=0;j<M;j++){
        C[0][j]=A[0][j];
        for(int i=1;i<N;i++){
            if(A[i][j]==1){
                C[i][j]=C[i-1][j]+A[i][j];
            }
            else{
                C[i][j]=0;
            }
        }
    }
    int max_area=INT_MIN,area;
    for(int i=0;i<N;i++){
        sort(C[i].begin(),C[i].end());
        int j=0;
        while(j<M&&C[i][j]==0){
            j++;
        }
        for(;j<M;j++){
            area=C[i][j]*(M-j);
            max_area=max(max_area,area);
        }
    }
    return max_area;
}