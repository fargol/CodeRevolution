// C/C++ program to print all interleavings of given two strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int minimum; 
// The main function that recursively prints all interleavings. 
// The variable iStr is used to store all interleavings (or 
// output strings) one by one.  
// i is used to pass next available place in iStr
void printIlsRecur (char *str1, char *str2, char *iStr, int m, 
                    int n, int i,int temp)
{
    // Base case: If all characters of str1 and str2 have been 
    // included in output string, then print the output string
    if (m==0 && n==0){
        temp++;
        if(minimum>temp)
          minimum=temp;
        //printf("%s\n", iStr) ;
      }
 
    // If some characters of str1 are left to be included, then
    // include the  first character from the remaining characters
    // and recur for rest
      int t1=0;
    if (m != 0)
    {
        iStr[i] = str1[0];
        if(i>0){
          if(iStr[i-1]!=iStr[i])
            t1++;
        }
        printIlsRecur (str1 + 1, str2, iStr, m-1, n, i+1,temp+t1);
    }
 
    // If some characters of str2 are left to be included, then
    // include the  first character from the remaining characters 
    // and recur for rest
    t1=0;
    if (n != 0&&str1[0]!=str2[0])
    {
        iStr[i] = str2[0];
        if(i>0){
          if(iStr[i-1]!=iStr[i])
            t1++;
        }
        printIlsRecur(str1, str2+1, iStr, m, n-1, i+1,temp+t1);
    }
}
 
// Allocates memory for output string and uses printIlsRecur()
// for printing all interleavings
void printIls (char *str1, char *str2, int m, int n)
{
   // allocate memory for the output string
   char *iStr= (char*)malloc((m+n+1)*sizeof(char));
 
   // Set the terminimumator for the output string
   iStr[m+n] = '\0';
 
   // print all interleavings using printIlsRecur()
   int temp=0;
   printIlsRecur (str1, str2, iStr, m, n, 0,temp);
 
   // free memory to avoid memory leak
   free(iStr); 
}
 
// Driver program to test above functions
int main()
{
    int T,A,B;
    cin>>T;
    char *str1,*str2;
    while(T--){
      minimum=INT_MAX;
      cin>>A>>B;
      str1=(char*)calloc(A+1,sizeof(char));
      str2=(char*)calloc(B+1,sizeof(char));
      scanf("%s",str1);
      scanf("%s",str2);
      printIls (str1, str2, strlen(str1), strlen(str2));
      cout<<minimum<<endl;
    }
      return 0;
}