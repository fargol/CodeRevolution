#include <bits/stdc++.h>
using namespace std;
int josephus(int n, int k);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		cout<<josephus(n,k)<<endl;
	}
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method */
int josephus(int n, int k)
{
   //Your code here
   if(n==1)
        return 1;
    else
        return (josephus(n-1,k)+k-1)%n+1;
}
