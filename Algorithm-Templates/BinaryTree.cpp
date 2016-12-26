#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct Node{
	int v;
	Node* lson;
	Node* rson;
};

Node* root;
bool ok=false;
void Insert(Node* &p,int v){
	if(p==NULL){
		p=(Node*)malloc(sizeof(Node));
		p->lson=p->rson=NULL;
		p->v=v;
		ok=true;
		return;
	}else if(p->lson==NULL) Insert(p->lson,v);
	else if(p->rson==NULL) Insert(p->rson,v);
	else{
		Insert(p->lson,v);
		if(ok) return;
		Insert(p->rson,v);
	}
}

void Inorder_Traverse(Node* p){
	if(p==NULL) return;
	else{
		Inorder_Traverse(p->lson);
		printf("%d ",p->v);
		Inorder_Traverse(p->rson);
	}
}

void PreOrder_Traverse(Node* p){
	if(p==NULL) return;
	else{
		printf("%d ",p->v);
		PreOrder_Traverse(p->lson);
		PreOrder_Traverse(p->rson);
	}
}

void PostOrder_Traverse(Node* p){
	if(p==NULL) return;
	else{
		PostOrder_Traverse(p->lson);
		PostOrder_Traverse(p->rson);
		printf("%d ",p->v);
	}
}

int main(){
	int N;
	cin>>N;
	while(N--){
		int op;cin>>op;
		switch(op){
			case 1:{
				ok=false;
				int v;cin>>v;
				Insert(root,v);
				break;
			}
			case 2:PreOrder_Traverse(root);putchar('\n');break;
			case 3:Inorder_Traverse(root);putchar('\n');break;
			case 4:PostOrder_Traverse(root);putchar('\n');break;
		}
	}
}