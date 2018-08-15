//Initial Template for C++
/* script for test case http://code.geeksforgeeks.org/PetjYq */
#include<bits/stdc++.h>
using namespace std;
string printOrder(string [], int , int );
string order;
bool f(string a,string b)
{
	int p1=0;int p2=0;
	for(int i=0;i<min(a.size(),b.size()) and p1 ==p2;i++ )
	{
		p1 = order.find(a[i]);
		p2 = order.find(b[i]);
	//	cout<<p1<<" "<<p2<<endl;
	}
	
	if(p1 == p2 and a.size()!=b.size())
	return a.size()<b.size();
	
	return p1<p2;
}
	
// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
    string s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    
        string ss = printOrder(s,n,k);
        order="";
        for(int i=0;i<ss.size();i++)
        order+=ss[i];
        
        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp,temp+n,f);
        
        bool f= true;
        for(int i=0;i<n;i++)
        if(s[i]!=temp[i])f=false;
        
        cout<<f;
        cout<<endl;
        
    }
	return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++
/*The function should return a string denoting the 
order of the words in the Alien Dictionary */
inline void dfs(stack<int> &st,bool **adjM,int k,int node,bool visited[]){
	visited[node]=true;
	for(int j=0;j<k;j++){
		//cout<<"here"<<endl;
		if(adjM[node][j]&&!visited[j])
			dfs(st,adjM,k,j,visited);
	}
	st.push(node);
	//cout<<"Stack- "<<st.top()<<endl;
}
inline string topoSort(bool **adjM,int k){
	stack<int> st;
	bool visited[k]={false};
	for(int i=0;i<k;i++){
		if(!visited[i])
			dfs(st,adjM,k,i,visited);
	}
	char ch;
	string S="";
	while(!st.empty()){
		ch=st.top()+97;
		S+=ch;
		st.pop();
	}
	return S;
}
string printOrder(string dict[], int N, int k)
{
   //Your code here
    bool **adjM=(bool**)calloc(k,sizeof(bool*));
    for(int i=0;i<k;i++)
    	adjM[i]=(bool*)calloc(k,sizeof(bool));
    for(int i=0;i<N-1;i++){
        string w1=dict[i];
        string w2=dict[i+1];
        int l=w1.length()>w2.length()?w2.length():w1.length();
        for(int j=0;j<l;j++){
            if(w1[j]!=w2[j]){
                adjM[w1[j]-'a'][w2[j]-'a']=true;
                break;
            }
        }
    }
    cout<<"adjM = \n";
    for(int i=0;i<k;i++){
    	for(int j=0;j<k;j++)
    		cout<<adjM[i][j]<<" ";
    	cout<<endl;
    }
    string S=topoSort(adjM,k);
    return S;
}