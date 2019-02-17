string Solution::countAndSay(int A) {
    string orig="1";
    string res="";
    while(--A){
        int c=1;
        for(int i=1;i<orig.size();i++){
            if(orig[i]==orig[i-1]){
                c++;
            }
            else{
                res+=to_string(c)+orig[i-1];
                c=1;
            }
        }
        res+=to_string(c)+orig[orig.size()-1];
        orig=res;
        res="";
    }
    return orig;
}
