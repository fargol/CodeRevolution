vector<vector<int> > Solution::threeSum(vector<int> &A) {
    int N=A.size();
    vector<vector<int> > res;
    sort(A.begin(),A.end());
    int itr=0;
    for(int i=0;i<N-2;i++){
       if(A[i]==A[i-1]){
           continue;
       }
       int j=i+1,k=N-1,sum;
       while(j<k){
           sum=A[i]+A[j]+A[k];
           if(sum==0){
               vector<int> tmp;
               tmp.push_back(A[i]);
               tmp.push_back(A[j]);
               tmp.push_back(A[k]);
               res.push_back(tmp);
           }
           if(sum<0){
               j++;
           }
           else if(sum>0){
               k--;
           }
           else{
               j++;
               while(j<k&&A[j]==A[j-1]){
                   j++;
               }
           }
       }
    }
    return res;
}
