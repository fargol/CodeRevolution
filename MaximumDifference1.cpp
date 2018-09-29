#include<bits/stdc++.h>
using namespace std;
 
int findMaxDiff(int [], int n);
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	cout<<findMaxDiff(a,n)<<endl;
   }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method */
int findMaxDiff(int A[], int n)
{
  //Your code here
  int NLS[n],NRS[n];
  stack<int> s;
  s.push(0);
  for(int i=0;i<n;i++){
    while(s.top()>=A[i])
      s.pop();
    NLS[i]=s.top();
    s.push(A[i]);
  }
  while(!s.empty())
    s.pop();
  s.push(0);
  for(int i=n-1;i>=0;i--){
    while(s.top()>=A[i])
      s.pop();
    NRS[i]=s.top();
    s.push(A[i]);
  }
  int maxDiff=0;
  for(int i=0;i<n;i++){
    maxDiff=max(maxDiff,abs(NLS[i]-NRS[i]));
  }
  return maxDiff;
}