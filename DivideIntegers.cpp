int divisor,r;
int Solution::divide(int A, int B){
    if(B==1){
        return A;
    }
    if(B==-1){
        long long int temp=0-A;
        A=temp;
        return A;
    }
    bool sign=false;
    if(A>0&&B<0){
        sign=true;
    }
    if(A<0&&B>0){
        sign=true;
    }
    A=abs(A),B=abs(B);
    long long int q=0;
    for(long long int t=0,i=31;i>=0;i--){
        long long temp=t+B<<i;
        if(temp<=A){
            q|=1LL<<i;
            t=temp;
        }
    }
    if(q>INT_MAX||q<INT_MIN){
        return INT_MAX;
    }
    if(sign){
        q=0-q;
    }
    return q;
}
