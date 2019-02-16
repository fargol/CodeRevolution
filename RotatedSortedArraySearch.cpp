int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int l=0,h=A.size()-1,mid;
    while(l<=h){
        mid=(l+h)>>1;
        if(A[mid]>A[h]){
            l=mid+1;
        }
        else if(A[mid]<A[h]){
            h=mid;
        }
        else{
            break;
        }
    }
    l=0;h=mid-1;
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
    l=mid;h=A.size()-1;
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
    return -1;
}