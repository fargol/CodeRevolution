#include<bits/stdc++.h>
using namespace std;
 int max_path_sum(int [], int [], int , int );
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        int result = max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method*/
 int max_path_sum(int A[], int B[], int l1, int l2)
{
    //Your code here
    int max_sum=0;
    int sum1=0,sum2=0;
    int i=0,j=0;
    while(i<l1&&j<l2){
        if(A[i]<B[j])
            sum1+=A[i++];
        else if(A[i]>B[j])
            sum2+=B[j++];
        else{
            max_sum+=max(sum1,sum2);
            sum1=sum2=0;
            max_sum+=A[i++];
            j++;
            /*while(i<l1&&j<l2&&A[i]==A[j]){
                max_sum+=A[i++];
                j++;
            }*/
        }
    }
    while(i<l1)
        sum1+=A[i++];
    while(j<l2)
        sum2+=B[j++];
    max_sum+=max(sum1,sum2);
    return max_sum;
}