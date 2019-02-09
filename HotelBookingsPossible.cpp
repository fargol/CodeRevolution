bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());
    int N=arrive.size(),count=0,i=0,j=0;
    while(i<N&&j<N){
        if(arrive[i]<depart[j]){
            count++;
            if(count>K){
                return false;
            }
            i++;
        }
        else if(arrive[i]==depart[j]){
            count++;
            count--;
            i++;
            j++;
        }
        else{
            count--;
            j++;
        }
    }
    return true;
}
