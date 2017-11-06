/*
NAME:-ANIRUDH KANNAN V P
ROLL NO:-201601004
BRANCH:- UG-2 CSE
*/

#include "bits/stdc++.h"
using namespace std;

void LCS(char a[],char b[], int n,int m){
int L[n+1][m+1],i=0,j=0,index,index1;
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
index1=index;
char ans[1000005];
i=n,j=m;
while(i>0 && j>0){
if(a[i-1] == b[j-1]) {ans[index-1]=a[i-1];i--;j--;index--;}
else if(L[i-1][j]>L[i][j-1]) i--;
else j--;        
}
cout<<ans<<"\n";
return;        
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
LCS(a,b,n,m);
}    
return 0;
}
