#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

string x;
int vis[1010];
bool g[1010];

const string d = "Bulbasaur";

int main() {
    g['B'] = g['b'] = g['l'] = g['u'] = g['a'] = g['s'] = g['r'] = 1;
    ios::sync_with_stdio(false);
    cin>>x;
    for(int i=0;i<x.length();++i) {
        if(g[x[i]]) {
            vis[x[i]] += 1;
        }
    }
    vis['u'] /= 2;
    vis['a'] /= 2;
    int minm = 0x3f3f3f3f;
    for(int i=0;i<d.size();++i) {
        minm = min(minm, vis[d[i]]);
    }
    cout<<minm;
    return 0;
}