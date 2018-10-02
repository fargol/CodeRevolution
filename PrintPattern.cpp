#include<iostream>
using namespace std;
void printseq(int N,int F,int t){
    cout<<N<<" ";
    if(N==F)
        return;
    if(N>0&&t==1)
        printseq(N-5,F,1);
    else
        printseq(N+5,F,2);
}
int main()
 {
	//code
	int T,N;
	cin>>T;
	while(T--){
	    cin>>N;
	    cout<<N<<" ";
	    printseq(N-5,N,1);
	    cout<<endl;
	}
	return 0;
}
