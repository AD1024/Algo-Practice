#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <map>
#include <vector>
using namespace std;

#define fi first
#define se second
#define mp(x,y) make_pair(x,y)
struct Node{
	int data;
	bool isl;
	Node* l;
	Node* r;
};

stack<Node*> s;
Node* root;

int ans1;
int ans = 0x3f3f3f3f;

void dfs(Node *p, vector< pair<int,int> > &v,int dep){
	if(p == NULL) return;
	else if(p->isl){
		ans1 = 0;
		for(int i=0;i<v.size();++i){
			ans1 += (dep-v[i].se)*v[i].fi;
		}
		ans = min(ans,ans1);
	}else{
		// cout<<p->data<<endl;
		v.push_back(mp(p->data,dep));
		dfs(p->l, v, dep+1);
		dfs(p->r, v, dep+1);
		v.pop_back();
	}
}
string str;
inline int readInt(int &i){
	int a = 0;
	while(isdigit(str[i]) && i<str.length()){
		a = a*10+str[i]-'0';
		++i;
	}
	--i;
	// cout<<a<<endl;
	return a;
}

int main(){
	ios::sync_with_stdio(false);
	cin>>str;
	for(int i=0;i<str.length();++i){
		if(str[i] == '(' || str[i] == ')') continue;
		if(str[i] == '.'){
			s.push(NULL);
		}else{
			root = new Node();
			root->data = readInt(i);
			// cout<<i<<endl;
			if(!root->data) root->isl = true;
			else root->isl = false;
			root->r = s.top();if(!s.empty()) s.pop();
			root->l = s.top();if(!s.empty()) s.pop();
			s.push(root);
		}
	}
	root=s.top();
	vector< pair<int,int> > k;
	dfs(root, k, 1);
	cout<<ans;
	return 0;
}