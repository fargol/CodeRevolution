void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int r=0,b=0,w=0;
    for(int i=0;i<A.size();i++){
        if(A[i]==0){
            r++;
        }
        else if(A[i]==2){
            b++;
        }
        else{
            w++;
        }
    }
    int i=0;
    for(int i=0;i<r;i++){
        A[i]=0;
    }
    for(int j=r;j<r+w;j++){
        A[j]=1;
    }
    for(int k=r+w;k<r+w+b;k++){
        A[k]=2;
    }
}
