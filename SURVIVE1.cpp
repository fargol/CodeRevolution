#include <bits/stdc++.h>
using namespace std;
int main(){

    int T,N,K,S,prod;
    double temp;
    cin>>T;
    while(T--){
        cin>>N>>K>>S;
        prod=K*S;
        temp=prod*1.0/(N*1.0);
        prod=ceil(temp);
        S-=S/7;
        if(prod<=S){
            cout<<prod<<endl;
        }
        else
            cout<<"-1\n";
    }
}   