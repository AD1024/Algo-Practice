#include <iostream>
#include <set>
#include <cstdio>
using namespace std;

string ch;
set<string> s,v;
int n;

int main(){
    scanf("%d",&n);int h;
    for(register int i=1;i<=n;i++){
        cin>>ch;
        s.insert(ch);
    }
    scanf("%d", &n);int sz;
    while(n--) {
    	sz = v.size();
    	cin>>ch;
    	if(s.count(ch) > 0) {
    		v.insert(ch);
    		if(v.size() - sz == 0) puts("REPEAT");
    		else puts("OK");
    	}else puts("WRONG");
    }
    return 0;
}