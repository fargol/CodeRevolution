int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int Na=A.size(),Nb=B.size(),Nc=C.size();
    int i=0,j=0,k=0;
    int res=INT_MAX;
    while(i<Na&&j<Nb&&k<Nc){
        int t1=A[i];
        int t2=B[j];
        int t3=C[k];
        int o1=max(t1,max(t2,t3));
        int o2=min(t1,min(t2,t3));
        int temp=o1-o2;
        res=min(res,temp);
        if(t1==o1){
            if(t2==o2){
                if(A[i]>B[j]){
                    j++;
                }
                else{
                    i++;
                }
            }
            else{
                if(C[k]>A[i]){
                    i++;
                }
                else{
                    k++;
                }
            }
        }
        else if(t2==o1){
            if(t3==o2){
                if(B[j]>C[k]){
                    k++;
                }
                else{
                    j++;
                }
            }
            else{
                if(A[i]>B[j]){
                    j++;
                }
                else{
                    i++;
                }
            }
        }
        else{
            if(t1==o2){
                if(C[k]>A[i]){
                    i++;
                }
                else{
                    k++;
                }
            }
            else{
                if(B[j]>C[k]){
                    k++;
                }
                else{
                    j++;
                }
            }
        }
    }
    return res;
}
