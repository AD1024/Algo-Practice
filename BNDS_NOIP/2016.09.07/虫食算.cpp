#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef char ch;
bool vis[1001];
ch s1[40],s2[40],s3[40];
int a[40],b[40],c[40];

int Idx[40];
bool flag;
int N;
bool upper[40];
inline int ok(int idx){
	int aa,bb,cc;
	int x,y;
	for(int i=N;i>=idx;++i){
		aa=a[i];bb=b[i];cc=c[i];
		if(Idx[aa]==-1 || Idx[bb]==-1 || Idx[cc]==-1) return true;
		x=Idx[aa]+Idx[bb];
		y=Idx[cc];
		if((x%N)!=y) return false;
	}
	return true;
}

void f(int idx){
	if(flag) exit(0);
	if(idx<0){
		if(ok(N)){
			flag=true;
			for(int i=0;i<N;++i){
				printf("%d ",Idx[i]);
			}
			return;
		}
		return;
	}else{
		//if(!ok(idx+1)) return;
		int tt;
		for(int i=N-1;i>=0;--i){
			if(Idx[a[idx]]==-1){
				if(!vis[i]){
					Idx[a[idx]]=i;
					vis[i]=true;
				}else continue;
			}
			for(int j=N-1;j>=0;--j){
				if(Idx[b[idx]]==-1){
					if(!vis[j]){
						Idx[b[idx]]=j;
						vis[j]=true;
						tt=Idx[a[idx]]+Idx[b[idx]];
						if(upper[idx]) ++tt;
						if(tt>=N){
							upper[idx-1]=true;
							tt%=N;
						}else{
							upper[idx-1]=false;
						}
						if(Idx[c[idx]]!=-1 && Idx[c[idx]]!=tt){
							Idx[b[idx]]=-1;
							vis[j]=false;
							continue;
						}else{
							if(!vis[tt]){
								vis[tt]=true;
								Idx[c[idx]]=tt;
								f(idx-1);
							}
							vis[j]=false;
							vis[tt]=false;
							Idx[b[idx]]=-1;
							Idx[c[idx]]=-1;
						}
					}
				}
			}
			vis[i]=false;
			Idx[a[idx]]=-1;
		}
	}
}


int main(){
	memset(Idx,-1,sizeof(Idx));
	cin>>N;
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	scanf("%s",s3+1);
	for(int i=1;i<=N;++i){
		a[i]=s1[i]-'A';
		b[i]=s2[i]-'A';
		c[i]=s3[i]-'A';
	}
	f(N);
	return 0;
}