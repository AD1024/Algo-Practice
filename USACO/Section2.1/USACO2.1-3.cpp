/*
ID: ccodera1
LANG: C++
TASK: sort3
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[1001],l[4],x,y,z,n;

int main(){
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        ++l[a[i]];
    }
    for (int i=1;i<=l[1];++i)
        if (a[i]!=1) ++x;
    for (int i=l[1]+1;i<=l[1]+l[2];++i)
        if (a[i]==3) ++y;
    for (int i=l[1]+l[2]+1;i<=n;++i)
        if (a[i]==2) ++z;
    if (y>z) x+=y;
    else x+=z;
    printf("%d\n",x);
    return 0;
}