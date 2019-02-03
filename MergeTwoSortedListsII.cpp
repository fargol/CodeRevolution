void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i=0,j=0,offset=0;
    for(int j=0;j<B.size();j++){

        while(i<A.size()&&B[j]>A[i])i++;
        A.insert(A.begin()+i,B[j]);
        i++;
    }
}
