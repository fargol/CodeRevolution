int Solution::gcd(int A, int B) {
    if(A==0){
        return B;
    }
    if(B==0){
        return A;
    }
    if(A%B==0){
        return B;
    }
    if(B%A==0){
        return A;
    }
    return gcd(B%A,A);
}