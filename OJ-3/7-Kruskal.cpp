/*
NAME:-ANIRUDH KANNAN V P
ROLL NO:-201601004
BRANCH:- UG-2 CSE
*/

#include"bits/stdc++.h"
using namespace std;
#define ll long long 

struct graphnode{
ll src,dest,w;
};

bool sortbyweight(graphnode & lhs,graphnode & rhs)
{
return lhs.w < rhs.w;
}

struct ufsubset{
ll par,ran;
};

ll uffind(ll i,struct ufsubset ufsubsets[]){
if(ufsubsets[i].par!=i){
ufsubsets[i].par=uffind(ufsubsets[i].par,ufsubsets);
}
return ufsubsets[i].par;
}

void ufunion(ll a,ll b,struct ufsubset ufsubsets[]){
ll roota=uffind(a,ufsubsets);
ll rootb=uffind(b,ufsubsets);
if(ufsubsets[roota].ran>ufsubsets[rootb].ran)
{
ufsubsets[rootb].par=roota;
}
else if(ufsubsets[roota].ran>ufsubsets[rootb].ran)
{
ufsubsets[roota].par=rootb;
}
else{
ufsubsets[rootb].par=roota;
ufsubsets[roota].ran+=1;
}
return;    
}

ll KMST(vector<graphnode> g,ll n){
struct ufsubset *ufsubsets = new ufsubset[n];
ll ii=0,maans=0,a,b,i;
for(i=0;i<n;i++){
ufsubsets[i].par=i;
ufsubsets[i].ran=0;
}
ll redge=0;
while(redge<n-1){
graphnode temp=g[ii];
ll a=uffind(temp.src,ufsubsets);
ll b=uffind(temp.dest,ufsubsets);
ll needge=temp.w;
ii+=1;
if(a!=b){
maans+=needge;
redge+=1;
ufunion(a,b,ufsubsets);
}
}
return maans;
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
    
    ll n,m,i,a,b,w;
    cin>>n>>m;
    vector<graphnode> g;
    for(i=0;i<m;i++){
        cin>>a>>b>>w;
        graphnode temp;
        temp.src=a;
        temp.dest=b;
        temp.w=w;
        g.push_back(temp);
    }
    sort(g.begin(),g.end(),sortbyweight);
    cout<<KMST(g,n);
    
}