vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> res;
    int N=A.size(),M=A[0].size();
    vector<vector<bool> > vis(N,vector<bool>(M,false));
    int i=0,j=0;
    char d='R';
    long long int count=N*M;
    while(count>0){
       if(i>=0&&j>=0&&i<N&&j<M&&!vis[i][j]){
           res.push_back(A[i][j]);
           vis[i][j]=true;
           count--;
           if(d=='R'){
               j++;
           }
           else if(d=='L'){
               j--;
           }
           else if(d=='U'){
               i--;
           }
           else{
               i++;
           }
       }
       else{
           if(d=='R'){
               j--;
               i++;
               d='D';
           }
           else if(d=='L'){
               j++;
               i--;
               d='U';
           }
           else if(d=='U'){
               i++;
               j++;
               d='R';
           }
           else{
               i--;
               j--;
               d='L';
           }
       }
    }
    return res;
}
