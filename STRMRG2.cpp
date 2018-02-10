#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
inline long long int max(long long int a, long long int b)
{
    return (a > b)? a : b;
}
inline long long int lcs( string &X, string &Y, long long int m, long long int n )
{
   long long int** L=(long long int**)calloc(m+1,sizeof(long long int*));
   for(long long int i=0;i<m+1;i++)
   		L[i]=(long long int*)calloc(n+1,sizeof(long long int));
   long long int i, j;
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}

int main(){
	long long int T,A,B,c1,c2,res;
	cin>>T;
	string s1,s2,s11,s22;
	while(T--){
		cin>>A>>B;
		cin>>s1;
		cin>>s2;
		s11=s22="";
		s11+=s1[0];
		for(long long int i=1;i<A;i++){
			if(s1[i-1]!=s1[i]){
				//c1++;
				s11+=s1[i];
			}
		}
		s22+=s2[0];
		for(long long int i=1;i<B;i++){
			if(s2[i-1]!=s2[i]){
				//c2++;
				s22+=s2[i];
			}
		}
		c1=s11.length();
		c2=s22.length();
		res=lcs(s11,s22,c1,c2);
		//res=0;cout<<c1<<" "<<c2<<" "<<lcs(s11,s22,c1,c2)<<endl;
		res-=c1+c2;
		res*=-1;
		cout<<res<<endl;
	}
}