int Solution::isPalindrome(string A) {
    int i=0,j=A.size()-1;
    while(i<j){
        if(('0'<=A[i]&&A[i]<='9')||('a'<=A[i]&&A[i]<='z')||('A'<=A[i]&&A[i]<='Z')){
            if(('0'<=A[j]&&A[j]<='9')||('a'<=A[j]&&A[j]<='z')||('A'<=A[j]&&A[j]<='Z')){
                if(tolower(A[i])!=tolower(A[j])){
                    return 0;
                }
                else{
                    i++;
                    j--;
                }
            }
            else{
                j--;
            }
        }
        else{
            i++;
        }
    }
    return 1;
}
