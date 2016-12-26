#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int num[100];
int N;
int a[8];
bool vis[10];
bool __idx[10];
/*
  1 2 3
    4 5
  d c b
g f e
h i j k
*/

inline int ps(int x){
	return x/10;
}

inline bool check(){
	int b,c,d,e,f,g,h,i,j,k;
	//第一行
	int carry=0;
	b=a[5]*a[3];
	if(b>=10){
		carry=ps(b);
		b%=10;
	}
	if(!__idx[b]) return false;
	c=a[5]*a[2];
	if(carry){
		c+=carry;
		carry=0;
	}
	if(c>=10){
		carry=ps(c);
		c%=10;
	}
	if(!__idx[c]) return false;
	d=a[5]*a[1];
	if(carry){
		d+=carry;
		carry=0;
	}
	if(d>=10) return false;
	if(!__idx[d]) return false;
	//第二行
	carry=false;
	e=a[4]*a[3];
	if(e>=10){
		carry=ps(e);
		e%=10;
	}
	if(!__idx[e]) return false;
	f=a[4]*a[2];
	if(carry){
		f+=carry;
		carry=0;
	}
	if(f>=10){
		carry=ps(f);
		f%=10;
	}
	if(!__idx[f]) return false;
	g=a[4]*a[1];
	if(carry){
		g+=carry;
		carry=0;
	}
	if(g>=10) return false;
	if(!__idx[g]) return false;

	//3rd line
	carry=0;
	/*
  	  d c b
	g f e
    h i j k
	*/
	k=b;
	j=c+e;
	if(j>=10){
		carry=ps(j);
		j%=10;
	}
	if(!__idx[j]) return false;
	i=d+f;
	if(carry){
		i+=carry;
		carry=0;
	}
	if(i>=10){
		carry=ps(i);
		i%=10;
	}
	if(!__idx[i]) return false;
	h=g;
	if(carry){
		h+=carry;
		carry=0;
	}
	if(h>=10) return false;
	if(!__idx[h]) return false;
	return true;
}
int ans=0;
void dfs(int idx){
	if(idx>5){
		if(check()){
			ans++;
		}
	}else{
		for(int i=1;i<=N;++i){
			a[idx]=num[i];
			dfs(idx+1);
		}
	}
}

int main(){
	freopen("alpha2.in","r",stdin);
	freopen("alpha2.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>num[i];
		__idx[num[i]]=true;
	}
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}