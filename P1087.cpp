#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10001;

struct node
{
	char s[16384];
	char Type;
	node* l;
	node* r;
}Nodes[MAXN];
node *root;
char ss[MAXN];
bool idx[2];
inline char getType(char str[],int len){
	for(int i=1;i<=len;i++){
		if(str[i]=='1'){
			idx[1]=true;
		}else{
			idx[0]=true;
		}
	}
	char type;
	if(idx[0] && idx[1]) type='F';
	else if(idx[0]) type='B';
	else type='I';
	return type;
}

void buildTree(char s[],node *n,int length,char Tp){
	if(s.size()<1){
		n=(node*)malloc(sizeof(node));
		n->s=s;
		n->Type=Tp;
	}else{
		char str[MAXN];
		for(int i=1;i<=length/2;i++){
			str[i]=s[i];
		}
		buildTree(str,n->l,length/2,getType(str,length/2));
		int cur=1;
		for(int i=length/2+1;i<=length;i++){
			str[cur++]=s[i];
		}
		buildTree(str,n->r,length/2,getType(str,length/2));
	}
}

int main(){
	cin>>n;
	scanf("%s",ss+1);
	root=(node*)malloc(sizeof(node));
	root->s=ss;
	root->type=getType(ss);
	buildTree(ss,root)
}