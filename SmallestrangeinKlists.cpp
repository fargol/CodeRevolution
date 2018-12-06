#include<limits.h>
#include<iostream>
using namespace std;
#define N 1000
void findSmallestRange(int arr[][N], int n, int k);
// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
	    findSmallestRange(arr, n, k);
    }   
	return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

// you are required to complete this function 
// function should print the required range
#include<bits/stdc++.h>

void findSmallestRange(int arr[][N], int n, int k)
{
      //code here
    priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > minHeap;
    int max_ele=INT_MIN,min_ele;
    for(int i=0;i<k;i++){
        max_ele=max(max_ele,arr[i][0]);
        minHeap.push(make_pair(arr[i][0],i));
    }
    int id=1;
    int min_range=INT_MAX;
    int b,e;
    while(id<=n){
        min_ele=minHeap.top().first;
        if(min_range>(max_ele-min_ele)){
            min_range=max_ele-min_ele;
            b=min_ele;
            e=max_ele;
        }
        max_ele=max(arr[minHeap.top().second][id],max_ele);
        minHeap.push(make_pair(arr[minHeap.top().second][id],minHeap.top().second));
        minHeap.pop();
        //cout<<id<<") b = "<<b<<"& e = "<<e<<endl;
        id++;
    }
    cout<<b<<" "<<e<<endl;
}