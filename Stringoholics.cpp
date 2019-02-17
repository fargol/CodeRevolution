#define M 1000000007
long long int gcd(long long int a,long long int b){
    if(a%b==0){
        return b;
    }
    if(b%a==0){
        return a;
    }
    return (b%a,a);
}
int Solution::solve(vector<string> &A) {
    vector<long long int> period(A.size());
    for(int i=0;i<A.size();i++){
        for(int j=1;;j++){
            long long int res=j*(j+1);
            res>>=1;
            if(res%A[i].size()==0){
                period[i]=j;
                //cout<<period[i]<<" ";
                break;
            }
        }
    }
    if(A.size()==1){
        return period[0];
    }
    long long int prod=1,LCM;
    int hcf=gcd(period[0],period[1]);
    prod=period[0]*period[1];
    prod%=M;
    LCM=prod/hcf;
    LCM%=M;
    for(int i=2;i<A.size();i++){
        hcf=gcd(LCM,period[i]);
        prod=LCM*period[i];
        prod%=M;
        LCM=prod/hcf;
        LCM%=M;
    }
    LCM%=M;
    return LCM;
}
