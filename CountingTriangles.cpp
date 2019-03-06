#define M 1000000007
int Solution::nTriang(vector<int> &A) {
    sort(A.begin(),A.end());
    long long int count=0;
    for(int i=0;i<A.size()-2;i++){
        int k=i+2;
        for(int j=i+1;j<A.size()-1;j++){
            int sum=A[i]+A[j];
            for(;k<A.size();k++){
                if(A[k]>=sum){
                    break;
                }
            }
            count+=(k-j-1);
            count%=M;
        }
    }
    return count;
}
