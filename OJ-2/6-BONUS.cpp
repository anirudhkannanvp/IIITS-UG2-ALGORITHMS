/*
NAME:-ANIRUDH KANNAN V P
ROLL NO:-201601004
BRANCH:- UG-2 CSE
*/

#include "bits/stdc++.h"
using namespace std;

FILE *fp2,*fp6,*fp8;


long int btd(int bin){
    long int ans=0,rem,number=bin,base=1;
    while(number>0){
        rem=number%10;
        ans+=rem*base;
        base*=2;
        number/=10;
    }
    //cout<<"decimal----"<<ans<<"\n";
    return ans;
}

void dtb(long int a){
    int cou=8,i;
    char str[9];
    str[8]='\0';
    for(i=0;i<8;i++)str[i]='0';
    while(a!=0){
        cou-=1;
        //cout<<a%2;
        if(a%2)
        {
        //fprintf(fp6,"%c",'1');
        str[cou]='1';
        }
        else
        {
        //fprintf(fp6,"%c",'0');
        str[cou]='0';
        }
        a/=2;
    }
    //for(i=cou;i<8;i++)
        //cout<<"0";
    //cout<<"binary----"<<str<<"\n";
    fprintf(fp6,"%s",str);
    //cout<<"\n";
    return ;
}

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
    //cout<<te<<"---";
    for(i=0;i<top;i++){fprintf(fp2,"%d",arr[i]);}
//cout<<"\n";
}

return;
}

char decodedsstr[1000000];

void decode(node * root, char *encoded){
char ans[100000];
int hcou=0,i;
fp8=fopen("mainout.txt","w");
node *curr=root;
for (i=0;i<strlen(encoded);i++)
{
if (encoded[i] == '1')
curr = curr->right;
else
curr = curr->left;
if (curr->left==NULL and curr->right==NULL)
{
ans[hcou++]= curr->data;
fprintf(fp8,"%c",curr->data);
ans[hcou+1]=0;
curr = root;
}
}

    //cout<<ans;
}



int main() {


    FILE *fp1,*fp3,*fp4,*fp5;
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    fp4=fopen("output1.txt","w");

int t,i,n,f1,c2;
    map<char,int> freq;
    //for(i=0;i<100005;i++)freq[i]=0;
    //char arr[1000005];
    char c1,c3;
i=0;
    /*for(i=0;i<1000005;i++)freq[i]=0;
    for(i=-127;i<=129;i++){
        c3=i;
        cout<<c3<<endl;
    }*/
    while(fscanf(fp1,"%c",&c1)!=EOF){
        //cout<<c1;
        //c2=c1;
        //cout<<c1<<"-"<<c3<<" ";
//freq[i]=f1;
//arr[c2]=c1;
        freq[c1]+=1;
//i+=1;
}
//arr[i]=0;

priority_queue<node *,vector<node *>,comparator1> minimumheap;

i=0;
    map<char,int> :: iterator ii;

    for(ii=freq.begin();ii!=freq.end();ii++){
node * temp;
temp= new node;
temp->left=NULL;
temp->right=NULL;
temp->freq=ii->second;
temp->data=ii->first;
    //cout<<arr[i]<<" ";
minimumheap.push(temp);
//i+=1;
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
    fclose(fp1);
    fp1=fopen("input.txt","r");
    while(fscanf(fp1,"%c",&c1)!=EOF){
        //cout<<c1;
        c2=c1;
        if(freq[c1]!=0)
print(minimumheap.top(),parr,0,c1);
    }

   //ENCODING
    int k=0,cou=0,cou1=0;
    long int no;
    char arr8[10];
    char ku;
    fclose(fp2);
    fp3=fopen("output.txt","r");
    while(fscanf(fp3,"%c",&c1)!=EOF){
        cou+=1;//count no of chracters
        if(k==8){

            no=atoi(arr8);
            //for(i=0;i<=7;i++)cout<<arr8[i]<<" ";
            no=btd(no);
            //cout<<"no--"<<no<<"\n";
            ku=no;
            //cout<<"c1--"<<ku<<"\n";
            fprintf(fp4,"%c",ku);
            //cout<<c1<<"\n";
                   k=0;
            cou1+=1;
            no=0;
        }
                       //cout<<"HELLO";
                       arr8[k++]=c1;
                       arr8[k+1]='\0';

    }

    //LAST BLOCK
    no=atoi(arr8);
    //for(i=0;i<=7;i++)cout<<arr8[i]<<" ";
    no=btd(no);
    //cout<<"no--"<<no<<"\n";
    ku=no;
    //cout<<"c1--"<<ku<<"\n";
    fprintf(fp4,"%c",ku);
    //cout<<c1<<"\n";
           //k=0;
    cou1+=1;
    no=0;
    //cout<<"LASt-BLOCK"<<k;


    //DECODING
    fclose(fp4);
    fp4=fopen("output1.txt","r");
    //fp5=fopen("output2.txt","w");
    fp6=fopen("output2.txt","w");
    int nowco=0;
    while(fscanf(fp4,"%c",&ku)!=EOF){
        nowco++;
        //cout<<"output1----"<<c1<<"\n";
        //cout<<"nowcow****"<<nowco<<"****"<<cou1<<"\n";

        if(nowco==cou1)break;

        long int integer;
        integer=ku;
        dtb(integer);
    }
    for(i=0;i<k;i++)
    fprintf(fp6,"%c",arr8[i]);
FILE *fp7;
//cout<<"HELLO";
fclose(fp3);
fclose(fp6);
fp7=fopen("output.txt","r");
char encodedstr[1000000];
int couen=0;
while(fscanf(fp7,"%c",&c1)!=EOF){
encodedstr[couen++]=c1;
}
encodedstr[couen++]='\0';
decode(minimumheap.top(),encodedstr);
  fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
    fclose(fp6);
    fclose(fp7);

return 0;
}
