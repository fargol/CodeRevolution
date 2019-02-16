int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int l=0,h=A.size()-1,mid;
    while(l<=h){
        mid=(l+h)>>1;
        if(A[mid]==B){
            return mid;
        }
        else if(A[mid]<B){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    if(l==0){
        if(A[l]>B){
            return 0;
        }
        else{
            return 1;
        }
    }
    if(l<A.size()){
        if(A[l-1]<B){
            return l;
        }
        else{
            return l-1;
        }    
    }
    else{
        return l;
    }
}
