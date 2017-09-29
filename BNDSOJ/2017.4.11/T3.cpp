#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <map>
#include <vector>
#include <cstdlib>
using namespace std;

struct Node{
	int data;
	Node* l;
	Node* r;
};

stack<Node*> s;
Node* root;

void dfs(Node* rt, int dep,int ch){
    if(rt == NULL) return;
    else if(rt->data == ch){
        cout<<dep<<endl;
        exit(0);
    }else{
        dfs(rt->l, dep+1, ch);
        dfs(rt->r, dep+1, ch);
    }
}

int main(){
	ios::sync_with_stdio(false);
	int N;int a;cin>>N;
	for(int i=0;i<N;++i){
        cin>>a;
		if(a == 0){
			s.push(NULL);
		}else{
			root = new Node();
			root->data = a;
			root->r = s.top();if(!s.empty()) s.pop();
			root->l = s.top();if(!s.empty()) s.pop();
			s.push(root);
		}
	}
	root=s.top();int k;cin>>k;
    dfs(root, 0, k);
	return 0;
}