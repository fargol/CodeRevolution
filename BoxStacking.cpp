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
typedef struct{
    int height;
    int length;
    int width;
    long long int baseArea;
}BOX;

bool cmp(const pair<long long int,BOX> a,const pair<long long int,BOX> b){
    return a.first<b.first;
}
int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    int nn=3*n;
    vector<pair<long long int,BOX> > arr(nn);
    int j=0;
    BOX bx;
    for(int i=0;i<nn;j++){
        bx.height=height[j];
        bx.width=width[j];
        bx.length=length[j];
        bx.baseArea=bx.length*bx.width;
        arr[i].first=bx.baseArea;
        arr[i].second=bx;
        i++;

        bx.height=length[j];
        bx.width=width[j];
        bx.length=height[j];
        bx.baseArea=bx.length*bx.width;
        arr[i].first=bx.baseArea;
        arr[i].second=bx;
        i++;

        bx.height=width[j];
        bx.width=length[j];
        bx.length=height[j];
        bx.baseArea=bx.length*bx.width;
        arr[i].first=bx.baseArea;
        arr[i].second=bx;
        i++;
    }
    sort(arr.begin(),arr.end(),cmp);
    //cout<<arr[0].first<<" : "<<arr[1].first<<endl;
    vector<int> dp(nn);
    dp[0]=arr[0].second.height;
    int max=dp[0];
    BOX bx1,bx2;
    for(int i=1;i<nn;i++){
        bx1=arr[i].second;
        dp[i]=bx1.height;
        for(int j=0;j<i;j++){
            bx2=arr[j].second;
            if((bx2.length<bx1.length && bx2.width<bx1.width)||(bx2.length<bx1.width&&bx2.height<bx1.width))
            {
                if(dp[i]<dp[j]+bx1.height)
                    dp[i]=dp[j]+bx1.height;
            }
        }
        if(max<dp[i])
            max=dp[i];
    }
    return max;
}