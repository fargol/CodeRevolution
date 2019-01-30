vector<vector<int> > Solution::generateMatrix(int A) {
    //vector<int> res;
    int N=A,M=A;
    vector<vector<int> > vis(N,vector<int>(M,0));
    int i=0,j=0;
    char d='R';
    long long int count=N*M,c=1;
    while(count>0){
       if(i>=0&&j>=0&&i<N&&j<M&&vis[i][j]==0){
           //res.push_back(A[i][j]);
           vis[i][j]=c;
           c++;
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
    return vis;
}
