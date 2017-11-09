/*
NAME:-ANIRUDH KANNAN V P
ROLL NO:-201601004
BRANCH:- UG-2 CSE
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "bits/stdc++.h"
using namespace std;


void swap(int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;
}

int medianfind(int arr[],int n){
int e1,e2,e3,e4,e5,t[3],k=0,i;
if(n==5){
        e1=min(arr[0],min(arr[1],min(arr[2],min(arr[3],arr[4]))));
        e5=max(arr[0],max(arr[1],max(arr[2],max(arr[3],arr[4]))));
        for(i=0;i<n;i++)if(arr[i]!=e1){if(arr[i]!=e5){t[k++]=arr[i];}}
        if(t[0]<t[1] && t[0]<t[2]){e2=t[0];e3=min(t[1],t[2]);e4=max(t[1],t[2]);}
        else if(t[1]<t[0] && t[1]<t[2]){e2=t[1];e3=min(t[0],t[2]);e4=max(t[0],t[2]);}
        else{e2=t[2];e3=min(t[0],t[1]);e4=max(t[0],t[1]);}
        return e3;
    }
    if(n==4){
        e1=min(arr[0],min(arr[1],min(arr[2],arr[3])));
         e4=max(arr[0],max(arr[1],max(arr[2],arr[3])));
         for(i=0;i<n;i++)if(arr[i]!=e1){if(arr[i]!=e4){t[k++]=arr[i];}}
         if(t[0]<t[1]){e2=t[0],e3=t[1];}
         else e2=t[1];e3=t[0];
         return e2;
    }
    if(n==3){
        e1=min(arr[0],min(arr[1],arr[2]));
        e3=max(arr[0],max(arr[1],arr[2]));
        for(i=0;i<n;i++)if(arr[i]!=e1){if(arr[i]!=e3){e2=arr[i];break;}}
        return e2;
    }
    if(n==2){
    	e1=min(arr[0],arr[1]);
    	e2=max(arr[0],arr[1]);
        return e1;
    }
   else{
        return arr[0];
    }
}

int quickpartition(int arr[],int low,int high,int spe){
int i=low,j;
for(i=low;i<high;i++){
//if(i==high)break;
if(arr[i]==spe)break;
//i+=1;
}
swap(&arr[high],&arr[i]);

i=low;
for(j=low;j<high;j++){
if(arr[j]<=spe){
swap(&arr[i],&arr[j]);
i++;
}
}
swap(&arr[i],&arr[high]);
return i;
}

int ithsmallest(int arr[],int low,int high,int k){
int n=high-low+1,i,n1,rem=n%5,temp[5],k1=0,te,medofmed,j,k2=0;
//if(n<=140)sort(arr,arr+n);return 1;
float n2=(n+4)/5;
n1=floor(n2);//if(n%5!=0)n1+=1;
int medianarr[n1];
//cout<<"HI "<<n2<<" ";
for(i=0;i<n/5;i++){
    	temp[0]=arr[i+low];
    	temp[1]=arr[i+1+low];
    	temp[2]=arr[i+2+low];
    	temp[3]=arr[i+3+low];
    	temp[4]=arr[i+4+low];
    	medianarr[i]=medianfind(temp,5);
    }
    //cout<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<" "<<temp[3]<<" "<<temp[4]<<"\n";
    	if(n%5!=0){
        if(n%5==1){
        medianarr[i] = arr[low+i*5];}
        if(n%5==2){
          temp[0]=arr[low+i*5];
        	temp[1]=arr[low+i*5+1];
        medianarr[i] = medianfind(temp, n%5);}
        if(n%5==3){
          temp[0]=arr[low+i*5];
        	temp[1]=arr[low+i*5+1];
          temp[2]=arr[low+i*5+2];
        medianarr[i] = medianfind(temp, n%5);}
        if(n%5==4){
          temp[0]=arr[low+i*5];
        	temp[1]=arr[low+i*5+1];
          temp[2]=arr[low+i*5+2];
          temp[3]=arr[low+i*5+3];
        medianarr[i] = medianfind(temp, n%5);}
            i++;}
if(i==1){
medofmed=medianarr[0];
}
else{
medofmed=ithsmallest(medianarr,0,n1-1,floor(n1/2));}
int pos=quickpartition(arr,low,high,medofmed);
if(pos-low==k-1)return arr[pos];
if(pos-low>k-1)return ithsmallest(arr,low,pos-1,k);
return ithsmallest(arr,pos+1,high,k-pos+low-1);
}

int main() {
//ios_base::sync_with_stdio(false);
//cin.tie(0);
int data,n,m,k,i,arr2[1000005],t;
scanf("%d",&t);
while(t--){
scanf("%d %d",&n,&k);
for(i=0;i<n;i++){
scanf("%d",&data);
arr2[i]=data;
}
printf("%d\n",ithsmallest(arr2,0,n-1,k));
}
return 0;
}
