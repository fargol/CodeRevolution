#include <iostream>
using namespace std;

int main() {
	//code
	int T,l1,l2;
	string S1,S2;
	cin>>T;
	while(T--){
	    cin>>S1>>S2;
	    l1=S1.length();
	    l2=S2.length();
	    int lcs[l1+1][l2+1];
	    lcs[0][0]=0;
	    for(int i=1;i<=l1;i++)
	    	lcs[i][0]=0;
	    for(int j=1;j<=l2;j++)
	    	lcs[0][j]=0;
	    for(int i=1;i<=l1;i++){
	    	for(int j=1;j<=l2;j++){
	    		if(S1[i-1]==S2[j-1]){
	    			lcs[i][j]=lcs[i-1][j-1]+1;
	    		}
	    		else{
	    			lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
	    		}
	    	}
	    }
	    //cout<<"LCS = "<<lcs[l1][l2]<<endl;
	    int scs=l1+l2-lcs[l1][l2];
	    cout<<scs<<endl;
	}
	return 0;
}