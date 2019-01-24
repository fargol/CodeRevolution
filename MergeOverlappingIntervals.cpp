/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool cmp(const Interval l,const Interval r){
     if(l.start>r.start){
         return false;
     }
     else if(l.start==r.start){
         return (l.end<r.end);
     }
     else{
         return true;
     }
     
 }
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(),A.end(),cmp);
    vector<Interval> res;
    Interval temp=A[0];
    for(int i=1;i<A.size();i++){
        if(A[i].start<=temp.end){
            temp.end=max(temp.end,A[i].end);
        }
        else{
            res.push_back(temp);
            temp=A[i];
        }
    }
    res.push_back(temp);
    return res;
}