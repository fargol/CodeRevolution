#include <bits/stdc++.h>

using namespace std;

string check_prime(int n){
    int c=0;
    if(n==1)
        return "Not prime";
    for(int i=1;i<=sqrt(n);i++)
        if(n%i==0)
            c++;
    if(c==1)
        return "Prime";
    else
        return "Not prime";
}


int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int p_itr = 0; p_itr < p; p_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string res=check_prime(n);
        cout<<res<<endl;
    }

    return 0;
}
