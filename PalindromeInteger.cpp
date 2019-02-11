int Solution::isPalindrome(int A) {
    if(A<0){
        return 0;
    }
    if(0<=A&&A<=9){
        return 1;
    }
    int NN=A;
    int N=0;
    while(NN>0){
        N*=10;
        N+=NN%10;
        NN/=10;
    }
    if(N==A){
        return 1;
    }
    return 0;
}
