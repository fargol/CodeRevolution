#include<bits/stdc++.h>
 using namespace std;
 #define MAX 10001
int kosaraju(vector<int> v[100001],int ,int );
int main()
{ 
   int t;
   cin>>t;
  while(t--)
   {   vector<int> v[100001];
        int a,b ;
   	cin>>a>>b;
       for(int i=0;i<b;i++)
           {  int m,n;
               cin>>m>>n;
               v[m].push_back(n);
           }
      
         
         int ans=kosaraju(v,a,b); 
         cout<<ans<<endl;
         for(int i=0;i<=a+1;i++)
        {    v[i].clear();   
         }
           
   }
return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The function takes an adjacency list representation of the graph g
    and two integers N and M as specified in the problem statement
    You are required to complete this method. */
inline void dfs(int node,vector<int> v[],stack<int> &st,int N,bool visited[]){
  if(!visited[node]){
    visited[node]=true;
    for(int i=0;i<v[node].size();i++)
      dfs(v[node][i],v,st,N,visited);
    st.push(node);
  }
}
int kosaraju(vector<int> v[100001], int N, int M)
{
    // Your code here
    stack<int> st;
    bool visited[N+1]={false};
    for(int i=1;i<=N;i++){
        dfs(i,v,st,N,visited);
    }
    vector<int> vT[100001];
    for(int i=1;i<=N;i++){
      for(int j=0;j<v[i].size();j++){
        vT[v[i][j]].push_back(i);
      }
    }
    memset(visited,false,N+1);
    int count=0;
    stack<int> stt;
    while(!st.empty()){
      if(!visited[st.top()]){
        dfs(st.top(),vT,stt,N,visited);
        count++;
      }
      st.pop();
    }
    return count;
}