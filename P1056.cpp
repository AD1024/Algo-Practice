#include<iostream>
using namespace std;
int hang[2000];//行能隔开的人
int lie[2000];//列能隔开的人
int main()
{
int M,N,K,L,D;//M行N列K横道L竖道D组交头接耳
cin>>M>>N>>K>>L>>D;
for(int i=1;i<=D;i++){
int x,y,p,q;//两个人坐标
cin>>x>>y>>p>>q;
if(x>p || y>q){
     swap(x,p);
     swap(y,q);//保证前小于后
}
  if(x+1==p)hang[x]++;//这行可以拆散的人++
  else lie[y]++;//这列可以拆散的
}
for(int i=1;i<=K;i=i+1){
  int hangzuida=-1,wei;//使其可以被覆盖
  for(int r=1;r<M;r++){
    if(hang[r]>hangzuida){
      hangzuida=hang[r];//赋值
      wei=r;
    }
  }
  hang[wei]=-1;//顺次最大
}
for(int i=1;i<=M-1;i=i+1){
  if(hang[i]==-1)cout<<i<<" ";
}
cout<<endl;
for(int i=1;i<=L;i=i+1){
  int liezuida=-1,wei;//使其可以被覆盖
  for(int r=1;r<N;r++)
  {
    if(lie[r]>liezuida)
    {
      liezuida=lie[r];//赋值
      wei=r;
    }
  }
  lie[wei]=-1;//顺次最大
}
for(int i=1;i<=N-1;i=i+1){
    if(lie[i]==-1)cout<<i<<" ";
}
  return 0;
}
