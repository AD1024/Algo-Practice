#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct Node{
	int data;
	Node* Next;
};

Node* head;
Node* tail;

inline void Push_back(int v){
	Node *q=(Node*)malloc(sizeof(Node));
	q->data=v;
	if(tail==NULL){
		head->Next=q;
		q->Next=head;
		tail=q;
	}else{
		tail->Next=q;
		q->Next=head;
		tail=q;
	}
}

inline void Push_Front(int v){
	Node* q=(Node*)malloc(sizeof(Node));
	q->data=v;
	if(tail==NULL){
		head->Next=q;
		q->Next=head;
		tail=q;
	}else{
		q->Next=head->Next;
		head->Next=q;
	}
}

inline void Traverse(){
	Node* cur=head->Next;
	while(cur!=head){
		cout<<cur->data<<' ';
		cur=cur->Next;
	}
}

int main(){
	head=(Node*)malloc(sizeof(Node));
	head->Next=head;
	int N;
	cin>>N;
	while(N--){
		int op;cin>>op;
		switch(op){
			case 1:{
				int v;cin>>v;
				Push_Front(v);
				break;
			}
			case 2:{
				int v;cin>>v;
				Push_back(v);
				break;
			}
			case 3:{
				Traverse();
				putchar('\n');
				break;
			}
		}
	}
}