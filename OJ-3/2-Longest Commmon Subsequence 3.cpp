/*
NAME:-ANIRUDH KANNAN V P
ROLL NO:-201601004
BRANCH:- UG-2 CSE
*/

#include "bits/stdc++.h"
using namespace std;

int LCS(char a[],char b[], int n,int m){
int L[n+1][m+1],i=0,j=0,index;
while(i!=n+1){
while(j!=m+1){
if(i==0 || j==0) L[i][j]=0;
else if(a[i-1]==b[j-1]) L[i][j]=1+L[i-1][j-1];
else L[i][j]=max(L[i][j-1],L[i-1][j]);
j++;
}
i+=1;
j=0;
}       
index=L[n][m];
return index;    
}

int main() {
int n,m,t;
char a[1000005],b[1000005];
cin>>t;
while(t--){    
scanf (" %[^\n]s", a);    
scanf (" %[^\n]s", b);    
n=strlen(a);
m=strlen(b);
cout<<LCS(a,b,n,m)<<"\n";
}    
return 0;
}
