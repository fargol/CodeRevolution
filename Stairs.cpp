int Solution::climbStairs(int A) {
    vector<int> ways(A+1);
    ways[0]=0;
    ways[1]=1;
    ways[2]=2;
    for(int i=3;i<=A;i++){
        ways[i]=ways[i-1]+ways[i-2];
    }
    return ways[A];
}
