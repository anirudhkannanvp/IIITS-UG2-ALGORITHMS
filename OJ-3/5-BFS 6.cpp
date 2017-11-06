/*
NAME:-ANIRUDH KANNAN V P
ROLL NO:-201601004
BRANCH:- UG-2 CSE
*/

#include"bits/stdc++.h"
using namespace std;
#define ll long long

void bfs(ll d[],vector<ll> g[],ll n,ll s){
for(ll i=0;i<n;i++){
d[i]=-1;
 }
d[s]=0;
queue<ll> q;
q.push(s);
ll v,u;
while(!q.empty()){
u=q.front();
q.pop();
vector<ll> :: iterator ite;
for(ite=g[u].begin();ite!=g[u].end();ite++){
v=*ite;
if(d[v]==-1){
q.push(v);
d[v]=d[u]+6;//6 GIVEN IN QUESTION
}
}
}
return;//END OF BFS FUNCTION
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
    
ll n,i,dist[10000000],a,b,t,m;
cin>>t;
while(t--){
cin>>n>>m;
vector<ll> g[n];
 for(i=0;i<m;i++){
cin>>a>>b;
g[a-1].push_back(b-1);
g[b-1].push_back(a-1);
}
ll d[1000000];
ll sour;
cin>>sour;//SOURCE
bfs(d,g,n,sour-1);
for(i=0;i<n;i++){
     if(i==sour-1)continue;
      cout<<d[i]<<" ";
    }
    cout<<"\n";
    }
    return 0;
}