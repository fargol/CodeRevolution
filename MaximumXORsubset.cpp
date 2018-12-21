#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define M 1000000007
#define ll long long

int maxSubarrayXOR(vector<int> set, int n){ 
    int index = 0; 
    for (int i = 31; i >= 0; i--){ 
        int maxInd = index; 
        int maxEle = INT_MIN; 
        for (int j = index; j < n; j++){ 
            if ( (set[j] & (1 << i)) != 0  && set[j] > maxEle ) 
                maxEle = set[j], maxInd = j; 
        } 

        if (maxEle == INT_MIN) 
        continue; 
  
        swap(set[index], set[maxInd]); 
  
        maxInd = index; 
  
        for (int j=0; j<n; j++){ 
            if (j != maxInd && (set[j] & (1 << i)) != 0) 
                set[j] = set[j] ^ set[maxInd]; 
        } 

        index++; 
    } 
  
    int res = 0; 
    for (int i = 0; i < n; i++) 
        res ^= set[i]; 
    return res; 
} 
int main(){
	ios::sync_with_stdio(true);
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		vector<int> arr(N);
		// int maxXor=0;
		for(int i=0;i<N;i++){
			cin>>arr[i];
			// maxXor^=arr[i];
		}
		cout<<maxSubarrayXOR(arr,N)<<endl;
	}
}