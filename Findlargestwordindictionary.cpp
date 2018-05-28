#include <bits/stdc++.h>
using namespace std;
int main() {
	//code
	int T,x,dl,flag;
	vector<pair<int,string> > arr(1010);
	string str;
	cin>>T;
	while(T--){
	    cin>>x;
	    for(int i=0;i<x;i++){
	        cin>>arr[i].second;
	        arr[i].first=arr[i].second.length();
	    }
	    cin>>str;
	    sort(arr.begin(),arr.begin()+x);
	    /*for(int i=x-1;i>=0;i--)
	        cout<<arr[i].second<<" ";
	    cout<<endl;*/
	    flag=-1;
	    for(int i=x-1;i>=0;i--){
	        dl=0;
	        for(int j=0;j<str.length();j++){
	            if(arr[i].second[dl]==str[j])
	                dl++;
	        }
	        if(dl==arr[i].second.length()){
	            flag=i;
	            break;
	        }
	    }
	    if(flag>-1)
	        cout<<arr[flag].second<<endl;
	}
	return 0;
}