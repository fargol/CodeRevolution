int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {

    int Na=A.size(),Nb=B.size(),Nc=C.size();
    int i=0,j=0,k=0;
    int res=INT_MAX;
    while(i<Na&&j<Nb&&k<Nc){
        int t1=abs(A[i]-B[j]);
        int t2=abs(B[j]-C[k]);
        int t3=abs(C[k]-A[i]);
        res=min(res,max(t1,max(t2,t3)));
        if(t1>=t2&&t1>=t3){
            if(A[i]>B[j]){
                j++;
            }
            else{
                i++;
            }
        }
        else if(t2>=t1&&t2>=t3){
            if(B[j]>C[k]){
                k++;
            }
            else{
                j++;
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
    return res;
}
