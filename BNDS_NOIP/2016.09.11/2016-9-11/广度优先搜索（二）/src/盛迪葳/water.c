#include <stdio.h>
int mx,my,z,flag=0;
int x[10001]={0},y[10001]={0},step[10001]={0},q[10001]={0};
/*
  1:x跤y 2:y跤x 3:x給雛 4:y給雛 5:x給諾 6:y給諾
*/ 
int check(int i,int p)
{
    if ((i==1 || i==5) && x[p]>0 || (i==2 || i==6) && y[p]>0 || i==3 && x[p]<mx || i==4 && y[p]<mx)
      return 1;
    return 0;
}
void bfs()
{
    int b[300][300]={0};
    int a,i,f=0,r=1,lx,ly,t=0;
    while (f!=r)
    {
      a=q[f];f++;
      for (i=1;i<=6;i++)
        if (check(i,a))
        {
          lx=x[a];ly=y[a];
          if (i==1)
          {
            if (lx>my-ly)
            {
              lx-=my-ly;ly=my;
            }
            else
            {
              ly+=lx;lx=0;
            }
          }
          if (i==2)
          {  
            if (ly>mx-lx)
            {
              ly-=mx-lx;lx=mx;
            }
            else
            {
              lx+=ly;ly=0;
            }
          }
          if (i==3) lx=mx;
          if (i==4) ly=my;
          if (i==5) lx=0;
          if (i==6) ly=0;
          step[r]=step[a]+1;
          if (ly==z)
          {
            printf("%d\n",step[t]);
            flag=1;
            return;
          }
          if (b[lx][ly]==0)
          {
            t++;
            q[r++]=t;
            x[t]=lx;y[t]=ly;
            b[x[t]][y[t]]=1;
          }
        }
      }
}
int main()
{
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
    scanf("%d%d%d",&mx,&my,&z);
    x[0]=mx;y[0]=0;
    bfs();
    if (flag==0) printf("No solution!\n");
    fclose(stdin);fclose(stdout);
    return 0;
}
