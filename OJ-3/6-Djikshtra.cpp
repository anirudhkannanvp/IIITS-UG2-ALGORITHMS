/*
NAME:-ANIRUDH KANNAN V P
ROLL NO:-201601004
BRANCH:- UG-2 CSE
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

 
void dijk(vector<pair<ll,ll>> v[],ll source,ll n,ll dist[]){
set<pair<ll,ll>>s;
s.insert(mp(0,source));
dist[source]=0;
ll j,z,weight;
 
while(!s.empty()){
pair<ll,ll> temp=*(s.begin());
s.erase(s.begin());
ll u=temp.second;
vector<pair<ll,ll>>::iterator ite;
for(ite=v[u].begin();ite!=v[u].end();ite++)
    {
     z=(*ite).first;
     weight=(*ite).second;
     if(dist[z]<weight)continue;
     if(dist[z]>dist[u]+weight)
       {   
         s.erase(mp(dist[z],z));
         dist[z]=dist[u]+weight;
         s.insert(mp(dist[z],z));
         }
    }
}

for(j=0;j<n;j++){
if(source==j)continue;
if(dist[j]==LONG_MAX)cout<<"-1"<<" ";
else cout<<dist[j]<<" ";
}
cout<<endl;
return;//END OF DIJSKSTRA FUNCTION
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	vector<pair<ll,ll>> v[100002];
	ll  t,ver,edg,i,j,so,de,we,qu,hello;
	cin>>t;
	while(t--){
	cin>>ver>>edg;
	for(i=0;i<ver;i++)
	v[i].clear();
	ll dist[100005];
    for(j=0;j<ver;j++){
    dist[j]=LONG_MAX;
    }
    i=0;
    while(i<edg)
    {
    cin>>so>>de>>we;
     v[so-1].pb(mp(de-1,we));
     v[de-1].pb(mp(so-1,we));
     i+=1;
    }
    cin>>qu;
    dijk(v,qu-1,ver,dist);//CALLING FUNCTION
	}
	return 0;
}