int Solution::maxArr(vector<int> &A) {
   int N=A.size();
   int minf=INT_MAX,maxf=INT_MIN,mins=INT_MAX,maxs=INT_MIN;
   for(int i=0;i<N;i++){
       minf=min(minf,A[i]+i);
       maxf=max(maxf,A[i]+i);
       mins=min(mins,A[i]-i);
       maxs=max(maxs,A[i]-i);
   }
   int ans=maxf-minf;
   ans=max(maxs-mins,ans);
   return ans;
}
