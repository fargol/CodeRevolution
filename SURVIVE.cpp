#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int main(){
    unsigned long long int T,K,d0,d1,d,i;
    unsigned long long int sum;
    cin>>T;
    int arr[4]={2,4,8,6};
    while(T--){
        cin>>K>>d0>>d1;
        sum=d0+d1;
        cout<<d0<<d1;
        for(i=2;i<K;i++){
            d=sum%10;
            cout<<d;
            /*if(d==0)
                break;
            if(d==2)
                break;*/
            sum+=d;
        }
        /*if(d==2){
            if(K-=i){
                for(int j=0;i<K%4;j++)
                    sum+=arr[j];
                sum+=(K/4)*20;
            }
        }*/
        cout<<'\n'<<sum<<endl;
        if(sum%3==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}   