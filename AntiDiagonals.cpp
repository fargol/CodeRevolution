inline bool valid(int i,int j,int N){
    if(i<0||j<0||i>=N||j>=N){
        return false;
    }
    return true;
}
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int> > soln;
    int N=A.size();
    for(int j=0;j<N;j++){
        int r=0;
        int c=j;
        vector<int> temp;
        while(valid(r,c,N)){
            temp.push_back(A[r][c]);
            r++;
            c--;
        }
        soln.push_back(temp);
    }
    for(int i=1;i<N;i++){
        int c=N-1;
        int r=i;
        vector<int> temp;
        while(valid(r,c,N)){
            temp.push_back(A[r][c]);
            r++;
            c--;
        }
        soln.push_back(temp);
    }
    return soln;
}
