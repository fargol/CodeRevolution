int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i=0,s,e,c;
    while(i<A.size()){
        auto it=A.begin();
        int oldi=i;
        if(i==0||(i>0&&A[i]!=A[i-1])){
            s=i;
            i++;
        }
        c=0;
        while(i<A.size()&&A[i]==A[i-1]){
            i++;
            c++;
        }
        if(c>0){
            e=i-1;
            A.erase(it+s+1,it+e);
        }
        i=oldi+1;
    }
    return A.size();
}
