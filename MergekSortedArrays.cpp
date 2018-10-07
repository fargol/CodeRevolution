#include<bits/stdc++.h>
#define N 11
using namespace std;
int *mergeKArrays(int arr[][N],int k);
void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}
int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k
class ELEMENT{
public:
	int key,i,j;
};
class Compare{
public:
	bool operator()(const ELEMENT a,const ELEMENT b){
		return a.key>b.key;
	}
};
int *mergeKArrays(int arr[][N], int k)
{
//code here
	priority_queue<ELEMENT,vector<ELEMENT>,Compare> min_heap;
	int *res=new int[k*k];
	ELEMENT ele;
	for(int i=0;i<k;i++){
		ele.key=arr[i][0];
		ele.i=i;
		ele.j=0;
		min_heap.push(ele);
	}
	for(int i=0;i<k*k;i++){
		ele=min_heap.top();
		min_heap.pop();
		res[i]=ele.key;
		if(ele.j<k-1){
			ele.key=arr[ele.i][ele.j+1];
			ele.i=ele.i;
			ele.j=ele.j+1;
			min_heap.push(ele);
		}
	}
	return res;
}