#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct node{
 int count;
 node* next[27];
 bool exist;
};

node *root;
int minm=10000;
void insert(char *s){
 int id;
 node* cur=root;
 char *str = s;
 bool dup=true;
 int cnt=0;
 while(*str){
  id=*str-'a';
  if(cur->next[id]==NULL){
   dup=false;
   cur->next[id]=(node*)malloc(sizeof(node));
  }
  cnt++;
  cur=cur->next[id];
  ++str;
  cur->count+=1;
 }
 if(dup)
  if(minm<cnt) minm=cnt;
 cur->exist=true;
}

int main(){
 root = (node*)malloc(sizeof(node));
 int n;
 cin>>n;
 while(n--){
  char* s;
  scanf("%s",s);
  insert(s);
 }
 cout<<minm<<endl;
}
