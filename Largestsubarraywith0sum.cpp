#include<bits/stdc++.h>
using namespace std;
int maxLen(int A[],int n);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        cout<<maxLen(A,N)<<endl;
    }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this function*/
int maxLen(int A[],int n)
{
  //Your code here
  unordered_map<int,int> hm;
  int sum[n+1];
  sum[0]=0;
  for(int i=1;i<=n;i++){
    sum[i]=A[i-1]+sum[i-1];
    hm[sum[i]]=i;
    //cout<<"sum[i] = "<<sum[i]<<endl;
  }
    int maxD=INT_MIN;
    for(int i=0;i<=n;i++){
        maxD=max(abs(i-hm[sum[i]]),maxD);
    }
    return maxD;
}
