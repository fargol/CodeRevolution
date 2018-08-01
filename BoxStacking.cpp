#include<bits/stdc++.h>
using namespace std;
int maxHeight(int height[],int width[],int length[],int n);
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

			int A[1000],B[1000],C[10001];
		for(int i=0;i<n;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			A[i]=a;
			B[i]=b;
			C[i]=c;
		}
		cout<<maxHeight(A,B,C,n)<<endl;
	}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/
int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    vector<tuple<long long int,int,int,int> > arr(3*n);
    int j=0;
    long long int base;
    for(int i=0;i<n;i++){
    	base=height[i]*width[i];
    	arr.push_back(make_tuple(base,length[i],height[i],width[i]));
    	j++;
    	base=height[i]*length[i];
    	arr.push_back(make_tuple(base,width[i],height[i],length[i]));
    	j++;
    	base=width[i]*length[i];
    	arr.push_back(make_tuple(base,height[i],width[i],length[i]));
    	j++;
    }
    vector<long long int> dp(3*n);
    sort(arr.rbegin(),arr.rend());
    dp[0]=get<1>(arr[0]);
    long long int maxDp=dp[0];
    for(int i=1;i<3*n;i++){
    	dp[i]=get<1>(arr[i]);
    	for(int j=0;j<i;j++){
    		if(get<2>(arr[j]) > get<2>(arr[i]) && get<3>(arr[j]) > get<3>(arr[i])){
    			if(dp[i]<dp[j]+get<1>(arr[i]))
    				dp[i]=dp[j]+get<1>(arr[i]);
    		}
    	}
    	if(maxDp<dp[i])
    		maxDp=dp[i];
    }
    return maxDp;
}