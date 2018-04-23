#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define pb(x) push_back(x)

using vi = vector<int>;

vi a,b;
vi c;
int N,K;

int main(){
	ios::sync_with_stdio(false);
	cin>>N>>K;
	int t;
	for(int i=0;i<N;++i){
		cin>>t;
		a.pb(t);
	}
	int bsum = 0;
	for(int i=0;i<N;++i){
		cin>>t;
		bsum += t;
		b.pb(t);
		c.pb(a[i] - t);
	}
	sort(c.begin(), c.end(), [&](int a, int b) -> bool{
		return a < b;
	});
	for(int i=0;i<K;++i){
		bsum += c[i];
	}
	for(int i=K;i<N && c[i] < 0;++i){
		bsum += c[i];
	}
	cout<<bsum<<'\n';
	return 0;
}
