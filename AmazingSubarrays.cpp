bool isVowel(char a){
    if(a=='a'||a=='A'){
        return true;
    }
    if(a=='e'||a=='E'){
        return true;
    }
    if(a=='i'||a=='I'){
        return true;
    }
    if(a=='o'||a=='O'){
        return true;
    }
    if(a=='u'||a=='U'){
        return true;
    }
    return false;
}
int Solution::solve(string A) {
    int MOD=10003;
    int res=0;
    for(int i=0;i<A.size();i++){
        if(isVowel(A[i])){
            int n=A.size()-i;
            res+=n%MOD;
            res%=MOD;
        }
    }
    res%=MOD;
    return res;
}
