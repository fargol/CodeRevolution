int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(x==0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    long long int res=1,X=x;
    X=X%d;
    while(n>0){
        if(n&1){
            res=(res*X)%d;
            n--;
        }
        n>>=1;
        X=(X*X)%d;
    }
    if(res<0){
        res=d+res;
    }
    return res;
}