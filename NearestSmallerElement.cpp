vector<int> Solution::prevSmaller(vector<int> &A) {
    int N=A.size();
    vector<int> G(N);
    G[0]=-1;
    stack<int> st;
    st.push(A[0]);
    for(int i=1;i<N;i++){
        if(st.empty()){
            G[i]=-1;
        }
        else{
            while(!st.empty()){
                if(A[i]<=st.top()){
                    st.pop();
                }
                else{
                    break;
                }
            }
            if(st.empty()){
                G[i]=-1;
            }
            else{
                G[i]=st.top();
            }
            st.push(A[i]);
        }
    }
    return G;
}
