#include<bits/stdc++.h>
using namespace std;
long long int floorSqrt(long long int x);
  
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		cout << floorSqrt(n) << endl;
	}
    return 0;   
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete
this function*/
long long int floorSqrt(long long int x) 
{
// Your code goes here   
	long long int low=0,high=x,mid,prod,ans;
	while(low<=high){
		mid=(low+high)/2;
		prod=mid*mid;
		if(prod==x)
			return mid;
		else if(prod>x)
			high=mid-1;
		else{
			low=mid+1;
			ans=mid;
		}
	}
	return ans;
	return mid;
}