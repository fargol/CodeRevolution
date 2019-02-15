int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int N=A.size(),M=A[0].size();
    int rl=0,rh=N-1,cl=0,ch=M-1,midr=-1,midc=-1,flag=0;
    while(rl<=rh){
        midr=(rl+rh)>>1;
        if(A[midr][0]<=B&&A[midr][M-1]>=B){
            flag=1;
            break;
        }
        else if(A[midr][0]>B){
             rh=midr-1;
        }
        else if(A[midr][M-1]<B){
            rl=midr+1;
        }
    }
    // if(flag==0){
    //     return 0;
    // }
    while(cl<=ch){
        midc=(cl+ch)>>1;
        if(A[midr][midc]<B){
            cl=midc+1;
        }
        else if(A[midr][midc]>B){
            ch=midc-1;
        }
        else{
            return 1;
        }
    }
    return 0;
}