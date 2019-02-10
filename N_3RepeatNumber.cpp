int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<pair<int,int> > arr;
    int N=A.size();
    for(int i=0;i<A.size();i++){
        if(arr.size()<1){
            arr.push_back({A[i],1});
        }
        else{
            if(arr[0].first==A[i]){
                arr[0].second++;
            }
            else if(arr[1].first==A[i]){
                arr[1].second++;
            }
            else{
                if(arr.size()<2){
                    arr.push_back({A[i],1});
                    continue;
                }
                arr[0].second--;arr[1].second--;
                N-=3;
            }
            if(arr[0].second<=0&&arr[1].second<=0){
                arr.clear();
            }
        }
    }
    if(arr.size()>0){
        for(int i=0;i<2;i++){
            int c=0;
            for(int j=0;j<A.size();j++){
                if(A[j]==arr[i].first)
                    c++;
            }
            if(c>A.size()/3){
                return arr[i].first;
            }
        }
        return -1;
    }
    else{
        return -1;
    }
}
