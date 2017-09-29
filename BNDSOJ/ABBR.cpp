#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define fi first
#define se second
#define mp(x,y) make_pair(x,y)

struct Op{
    int T;
    char op;
};

int pos;
char D;
int N,K,L;

bool cmp(Op a,Op b){
    return a.T < b.T;
}

map<pair<int,int>, bool> g;

vector<Op> ops;

int main(){
    // ios::sync_with_stdio(false);
    cin>>N;
    cin>>K;

}