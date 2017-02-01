#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long
ll ans;
int main(){
	ll a,b,c,d;ll k;
	cin>>a>>b>>c>>d>>k;
	ll lower = max(a,c);
	ll upper = min(b,d);
	if(lower <= upper){
		ans = upper - lower + 1;
	}
	if(k <= upper and k >= lower) ans--;
	cout<<ans;
	return 0;
}