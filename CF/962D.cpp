#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Node{
    ll v;
    int p;
    Node(){}
    Node(ll vv, int pp) {
        v = vv;p = pp;
    }
    bool operator <(Node b) const{
        if(v != b.v) return v < b.v;
        else return p < b.p;
    }
    bool operator >(Node b) const{
        if(v != b.v) return v > b.v;
        else return p > b.p;
    }
};

priority_queue<Node, vector<Node>,  greater<Node> > q;
vector<Node> v;
map<ll, bool> a;
int N;
int cnt;
ll ans[150010];

int main() {
    scanf("%d", &N);ll t;
    for(int i=1;i<=N;++i) {
        scanf("%lld", &t);
        q.push(Node(t, i));
        if(!a[t]) {
            cnt += 1;
        }
    }
    do {
        Node k = q.top();q.pop();
        if(q.size()){
            if(k.v != q.top().v) {
                v.push_back(k);cnt--;continue;
            } else {
                k = q.top();q.pop();
                q.push(Node(k.v << 1, k.p));
            }
        } else {
            v.push_back(k);
        }
    } while(cnt && q.size());
    sort(v.begin(), v.end(), [=](Node a, Node b) -> bool {
        return a.p < b.p;
    });
    printf("%lu\n", v.size());
    for(auto i: v) {
        printf("%lld ", i.v);
    }
    return 0;
}