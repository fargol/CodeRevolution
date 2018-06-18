#include <bits/stdc++.h>

using namespace std;



int main()
{
    string a;
    getline(cin, a);

    string b;
    getline(cin, b);
    
    vector<int> stra(26,0),strb(26,0);
    for(int i=0;i<a.length();i++)
        stra[a[i]-'a']++;
    for(int i=0;i<b.length();i++)
        strb[b[i]-'a']++;
    int res=0;
    for(int i=0;i<26;i++)
        res+=abs(stra[i]-strb[i]);
    cout<<res<<endl;
    return 0;
}
