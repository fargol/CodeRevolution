#include <bits/stdc++.h>
using namespace std;
int maxSumSubarray(int [], int );
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		cout<<maxSumSubarray(a,n)<<endl;
	}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete below method */
int maxSumSubarray(int A[], int n)
{
    //Your code here
    int fw[n];
    int bw[n];
    int curr_max,max_so_far;
    fw[0]=curr_max=max_so_far=A[0];
    for(int i=1;i<n;i++){
    	curr_max=max(A[i],curr_max+A[i]);
    	max_so_far=max(max_so_far,curr_max);
    	fw[i]=curr_max;
    }
    cout<<"h= "<<max_so_far<<endl;
    max_so_far=curr_max=bw[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--){
    	curr_max=max(A[i],curr_max+A[i]);
    	max_so_far=max(max_so_far,curr_max);
    	bw[i]=curr_max;
    }
    for(int i=1;i<n-1;i++){
    	max_so_far=max(max_so_far,fw[i-1]+bw[i+1]);
    }
    return max_so_far;
}