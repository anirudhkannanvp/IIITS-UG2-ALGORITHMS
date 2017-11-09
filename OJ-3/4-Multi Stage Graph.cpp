/*
NAME:-ANIRUDH KANNAN V P
ROLL NO:-201601004
BRANCH:- UG-2 CSE

*/

#include "bits/stdc++.h"
using namespace std;

int main() {

ios_base::sync_with_stdio(false);
cin.tie(0);

int t,n,n1,a,b,w,i,j,m;
int g[1005][1005];
cin>>t;
while(t--){    

for(i=1;i<=1000;i++)
{
for(j=1;j<=1000;j++)
g[i][j]=-1;
}
cin>>n>>m;



for(i=0;i<m;i++)
{
cin>>a>>b>>w;
g[a][b]=w;
g[b][a]=w;
}


int dp[1005],ans=INT_MAX,temp;

for(i=1;i<=1000;i++)
dp[i]=INT_MAX;
dp[1]=0;



for(i=2;i<=n;i++)
{
for(j=1;j<=i-1;j++)
{
if(g[i][j]!=-1){
dp[i]=min(dp[i],dp[j]+g[i][j]);
}
}
}

cout<<dp[n]<<"\n";

}    
return 0;
}
