vector<int> Solution::flip(string A) {
    int N=A.size();
    vector<int> arr(N);
    for(int i=0;i<N;i++){
        if(A[i]=='0'){
            arr[i]=1;
        }
        else{
            arr[i]=-1;
        }
    }
    int max_so_far=0,max_sum=INT_MIN,beg=0,end=0,beg1=0,end1=0;
    for(int i=0;i<N;i++){
        //cout<<"arr = "<<arr[i]<<endl;
        max_so_far+=arr[i];
        if(max_sum<max_so_far){
            max_sum=max_so_far;
            beg=beg1;
            end1=i;
            end=end1;
        }
        if(max_so_far<0){
            max_so_far=0;
            beg1=i+1;
            end1=i+1;
        }
    }
    //cout<<max_sum<<endl;
    vector<int> res;
    if(max_sum<0){
        return res;
    }
    else{
        res.push_back(beg+1);
        res.push_back(end+1);
        return res;
    }
}
