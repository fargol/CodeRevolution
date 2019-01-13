vector<int> Solution::solve(int R, vector<int> &S) {
    vector<pair<int,int> > newS;
    int prev=INT_MAX;
    for(int i=0;i<S.size();i++){
        if(S[i]<prev){
            newS.push_back({i,S[i]});
            prev=S[i];
        }
    }
    int n=newS.size();
    int temp=newS[n-1].second;
    vector<int> res;
    int i=0;
    while(i<n){
        if(R>=newS[i].second&&(1+(R-newS[i].second)/temp)==R/temp){
            res.push_back(newS[i].first);
            R-=newS[i].second;
        }
        else{
            i++;
        }
    }
    return res;
}
