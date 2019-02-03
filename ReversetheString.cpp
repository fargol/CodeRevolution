#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define M 1000000007
int main(){
	ios::sync_with_stdio(true);
	string A="   fwbpudnbrozzifml    osdt ulc jsx kxorifrhubk ouhsuhf sswz qfho dqmy sn myq igjgip iwfcqq";
	//cin>>A;
	string &B=A;
	string C=B;
    stringstream s(C);
    stack<string> words;
    string w;
    while(s>>w){
        //cout<<w<<" ";
        words.push(w);
    }
    w="";
    while(!words.empty()){
        w+=words.top();
        w+=" ";
        words.pop();
    }
    cout<<w<<endl;
}