#include<stdio.h>
#include<stdlib.h>
int h,n,choose[2000]={0},b[12][12]={0},total=0;
int x1[12]={0},x2[12]={0},x3=0,x4=0;
void prt()
{
  int i,j;
  for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
        printf("%d ",b[i][j]);
      printf("\n");
    }
  printf("\n");
  total++;
  return;
}      
void tzy(int i)
{
  int j,x,y,a1,a2,s=0,ans1=0,ans2=0;
  x=i/n+1;y=i%n+1;
  for (j=1;j<=n*n;j++)
    if((choose[j]==0)&&((x1[x]+j)<=h)&&((x2[y]+j)<=h))
      if((x!=y)||((x3+j)<=h))
        if(((x+y)!=(n+1))||((x4+j)<=h))
          {
            if((x==n)&&(y==n))
              {
                b[x][y]=j;
                choose[j]=1;
                x1[x]+=j;
                x2[y]+=j;
                x3+=j;
                for(a1=1;a1<=n;a1++) if(x1[a1]==h) s++;
                if(s==n) ans1=1;s=0;
                for(a1=1;a1<=n;a1++) if(x2[a1]==h) s++;
                if(s==n) ans2=1;s=0;
                if((ans1)&&(ans2)&&(x3==h)&&(x4==h)) prt();
                ans1=0;ans2=0;
                b[x][y]=0;
                choose[j]=0;
                x1[x]-=j;
                x2[y]-=j;
                x3-=j;
              }
              else
              {
                b[x][y]=j;
                choose[j]=1;
                x1[x]+=j;
                x2[y]+=j;
                if(x==y) x3+=j;
                if((x+y)==(n+1)) x4+=j;
                tzy(i+1);
                b[x][y]=0;
                choose[j]=0;
                x1[x]-=j;
                x2[y]-=j;
                if(x==y) x3-=j;
                if((x+y)==(n+1)) x4-=j;
              }
          }
  return;
}
int main()
{
  int i;
  freopen("h.in","r",stdin);
  freopen("h.out","w",stdout);
  scanf("%d",&n);
  h=(n*n+1)*n/2;
  tzy(0);
  printf("total=%d",total);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
