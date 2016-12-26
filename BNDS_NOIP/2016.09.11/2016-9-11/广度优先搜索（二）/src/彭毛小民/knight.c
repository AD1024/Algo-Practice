#include <stdio.h>
#include <stdlib.h>
int n,m,f[51][51]={0};
void open()
{
  freopen("knight.in","r",stdin);   
  freopen("knight.out","w",stdout);
}
void clsoe()
{
  fclose(stdin);
  fclose(stdout);     
}
void init()
{
  scanf("%d%d",&n,&m);
}
int ans(int a)
{
  if (a<0) return -a;
  return a;
}
void go()
{
  int ix,iy,jx,jy;
  for (ix=1;ix<n;ix++)
    for (iy=1;iy<m;iy++)
      for (jx=1;jx<=n;jx++)
        for (jy=1;jy<=m;jy++)
          if (f[ix][iy]>0  || (ix==1 && iy==1))
            if (abs(ix-jx)+abs(iy-jy)==3 && abs(abs(ix-jx)-abs(iy-jy))==1)
              if (f[jx][jy]==0 || f[ix][iy]+1<f[jx][jy])
                f[jx][jy]=f[ix][iy]+1;    
}
int main()
{
  open();
  init();
  go();
  if (f[n][m]>0) printf("%d",f[n][m]);
  else printf("No solution!");
  close();
  return 0;
}
