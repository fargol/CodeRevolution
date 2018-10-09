#include<bits/stdc++.h>
using namespace std;
bool isSubSequence(vector<int> s1,vector<int> s2, int m, int n)
{
   
    if (m == 0) return true;
    if (n == 0) return false;
 
   
    if (s1[m-1] == s2[n-1])
        return isSubSequence(s1, s2, m-1, n-1);
 
  
    return isSubSequence(s1, s2, m, n-1);
}
vector<int> find3Numbers(vector<int> , int );
// Driver program to test above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> a(n+1);
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		  vector<int> res = find3Numbers(a, n);
    
    	 
    	  
    	  if(res.size()==0)
    	  {
    	  	cout<<0<<endl;
    	  }
    	  else if(res[0]<res[1] and res[1]<res[2])
          cout<<isSubSequence(res,a,res.size(),n)<<endl;
          else
          cout<<0<<endl;
	}
    
  
    return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The function returns a vector containing the 
increasing sub-sequence of length 3 if present
else returns an empty vector */
vector<int> find3Numbers(vector<int> A, int N)
{
   //Your code here
  vector<int> res;
  int smaller[N],greater[N];
  smaller[0]=-1;
  int min=0,max=N-1;
  for(int i=1;i<N;i++){
    if(A[i]<=A[min]){
      smaller[i]=-1;
      min=i;
    }
    else{
      smaller[i]=min;
    }
  }
  greater[N-1]=-1;
  for(int i=N-2;i>=0;i--){
    if(A[i]>=A[max]){
      greater[i]=-1;
      max=i;
    }
    else{
      greater[i]=max;
    }
  }
  for(int i=1;i<N-1;i++){
    if(smaller[i]!=-1&&greater[i]!=-1){
      res.push_back(A[smaller[i]]);
      res.push_back(A[i]);
      res.push_back(A[greater[i]]);
      return res;
    }
  }
  return res;
}