
#include <bits/stdc++.h>
using namespace std;
bool isInterleave(string A, string B, string C);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		cout<<isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method */
bool isInterleave(string A, string B, string C) 
{
    //Your code here
    int flag1=0,flag2=0;
    int ca=0,cb=0,cc=0;
    for(int i=0;i<C.length();i++){
        if(C[i]==A[ca])
            ca++;
        else if(C[i]==B[cb])
            cb++;
        else{
            flag1=1;
            break;
        }
    }
    ca=cb=0;
    for(int i=0;i<C.length();i++){
        if(C[i]==B[cb])
            cb++;
        else if(C[i]==A[ca])
            ca++;
        else{
            flag2=1;
            break;
        }
    }
    if(!flag1||!flag2)
        return true;
    else
        return false;
}
