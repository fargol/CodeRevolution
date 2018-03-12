    #include <bits/stdc++.h>
    using namespace std;
    #define endl '\n';
    int main(){
      ios::sync_with_stdio(false);
      unsigned int N,Q,l,r,x,c1,c0,add;
      //unsigned int sum,max_sum; 
      cin>>N>>Q;
      vector<unsigned int> A(N,0);
      vector<vector<unsigned int> > Abc(N,vector<unsigned int>(31,0));
      vector<vector<unsigned int> > Ab(N,vector<unsigned int>(31,0));
      for(unsigned int &i:A)
        	cin>>i;

    	for(int i=30;i>=0;i--){
        	add=1<<i;
        	if(A[0]&add)
        		Ab[0][i]=Abc[0][i]=1;
        	for(unsigned int j=1;j<N;j++){
        		if(A[j]&add)
        			Ab[j][i]=1;
        		Abc[j][i]=Abc[j-1][i]+Ab[j][i];
        	}
        }
      while(Q--){
        cin>>l>>r;
        l--;r--;
        x=0;
        for(int i=30;i>=0;i--){
        	add=1<<i;
        	c1=Abc[r][i]-Abc[l][i]+Ab[l][i];
        	c0=(r-l+1)-c1;
        	//cout<<"i = "<<i<<" c1 = "<<c1<<" c0 = "<<c0<<endl;
        	if(c0>c1)
        		x+=add;
        }
        //x>>=1;
        cout<<x<<endl;
    }
  }
      