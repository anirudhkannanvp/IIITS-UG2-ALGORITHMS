/*
NAME:-ANIRUDH KANNAN V P
ROLL NO:-201601004
BRANCH:- UG-2 CSE
*/

#include "bits/stdc++.h"
using namespace std;

struct node{
node *left;
char data;
int freq;
node *right;
}mainobj;

struct comparator1
{
bool operator()(node *x,node *y)
{
return y->freq<x->freq;
}
}macomobj;


void print(node * root,int arr[],int top,char te){
if(root->left!=NULL){
arr[top]=0;
print(root->left,arr,top+1,te);
}
if(root->right!=NULL){
arr[top]=1;
print(root->right,arr,top+1,te);
}

if(root->data==te){
int i;
for(i=0;i<top;i++)cout<<arr[i];
cout<<"\n";
}

return;
}

int main() {

ios_base::sync_with_stdio(false);
cin.tie(0);

int t,freq[1000005],i,n,f1;
char arr[1000005],c1;
cin>>t;
while(t--){    

cin>>n;
i=0;
while(i!=n){
cin>>c1>>f1;
freq[i]=f1;
arr[i]=c1;
i+=1;
}
arr[i]=0;

priority_queue<node *,vector<node *>,comparator1> minimumheap;

i=0;
while(i!=n){
node * temp;
temp= new node;
temp->left=NULL;
temp->right=NULL;
temp->freq=freq[i];
temp->data=arr[i];
minimumheap.push(temp);
i+=1;
}


while(minimumheap.size()!=1){
node *leftinsert,*rightinsert,*topa;
leftinsert=minimumheap.top();minimumheap.pop();
rightinsert=minimumheap.top();minimumheap.pop();
topa= new node;
topa->left=leftinsert;
topa->right=rightinsert;
topa->freq=leftinsert->freq+rightinsert->freq;
topa->data='%';//% DENOTES NOT A LEAF NODE AND WE HAVE TO TRAVERSE FURTHER WHILE PRINTING HUFFMAN TREE
minimumheap.push(topa);
}

int parr[100005];
for(i=0;i<n;i++)
print(minimumheap.top(),parr,0,arr[i]);

}    
return 0;
}