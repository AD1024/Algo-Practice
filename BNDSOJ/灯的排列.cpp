#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int r,b;
int N;
int main(){
	cin>>N;
	cin>>r>>b;
	int up = N-(r+b);
	cout<<(up+1)*up;
	return 0;
}