int Solution::threeSumClosest(vector<int> &A, int B) {
    int N=A.size();
    sort(A.begin(),A.end());
    int mindiff=INT_MAX,res;
    vector<int> temp(N);
    for(int i=0;i<N;i++){
        temp[i]=B-A[i];
    }
    for(int i=0;i<N;i++){
        int j=i+1,k=N-1;
        while(j<k){
            int diff=abs(temp[i]-A[j]-A[k]);
            if(mindiff>diff){
                mindiff=diff;
                res=A[i]+A[j]+A[k];
            }
            if(A[j]+A[k]>temp[i]){
                k--;
            }
            else if(A[j]+A[k]==temp[i]){
                break;
            }
            else{
                j++;
            }
        }
    }
    return res;
}
