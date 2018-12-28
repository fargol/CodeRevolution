#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;
bool areKAnagrams(string str1, string str2, int k);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		if (areKAnagrams(str1, str2, k) == true)
			cout<<"1";
		else
			cout<<"0";
	}
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below*/
bool areKAnagrams(string str1, string str2, int k)
  {
    //add code here.
    if(str1.length()!=str2.length()){
    	return false;
    }
    int alpha1[26]={0},alpha2[26]={0};
    for(auto ch:str1){
    	alpha1[ch-'a']++;
    }
    for(auto ch:str2){
    	alpha2[ch-'a']++;
    }
    int K=k;
    for(int i=0;i<26;i++){
    	if(alpha1[i]!=alpha2[i]){
    		k-=(max(alpha1[i],alpha2[i])-min(alpha1[i],alpha2[i]));
    	}
    	if(k<-K){
    		return false;
    	}
    }
    return true;
 }