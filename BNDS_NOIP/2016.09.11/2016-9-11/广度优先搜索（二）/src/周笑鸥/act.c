#include <stdio.h>
#include <string.h>
int jc[8]={0,1,2,6,24,120,720,5040},a[40321]={0};
int s[10000][9]={0},ls[9],anss[9]={0};
int s1[10000],i=1,f,r,n;
int same(int a1[9],int a2[9])
{int j=8,ii;
   for (ii=1;ii<=8;ii++)
     if (a1[ii]==a2[ii]) j--;
   return j;
}
void copy(int a1[9],int a2[9])
{int j;
   for (j=1;j<=8;j++)
     a1[j]=a2[j];
}
long cd(int aa[9])
{
 int j,k,smaller[9]={0};
  n=0;
  for (j=2;j<=8;j++)
    for (k=1;k<=j-1;k++)
      if (aa[k]>aa[j])
        smaller[k]++;
  for (j=1;j<=7;j++)
    n=n+smaller[j]*jc[9-j];
  n++;
  return n;
}
void exchange()
{int a;
  if (i==1)
  {int j;
    for (j=1;j<=4;j++)
    {
      a=ls[j];
      ls[j]=ls[j+4];
      ls[j+4]=a;
    }
  }
  else if (i==2)
  {int j;
    for (j=1;j<=5;j+=4)
    {
      a=ls[j];
      ls[j]=ls[j+3];
      ls[j+3]=ls[j+2];
      ls[j+2]=ls[j+1];
      ls[j+1]=a;
    }
  }
  else if (i==3)
  {
    a=ls[2];
    ls[2]=ls[6];
    ls[6]=ls[7];
    ls[7]=ls[3];
    ls[3]=a;
  }
}
void bfs()
{int jl=0;
  f=0;r=1;
  while (f<r)
  {
    for (i=1;i<=3;i++)
    {
      copy(ls,s[f]);
      exchange();
      if (same(ls,anss)==0)
      {
        printf("%d\n",s1[f]+1);
        f=r+10;
        jl=1;
        break;
      }
      if (a[cd(ls)]==0)
      {
        a[cd(ls)]=1;
        r++;
        copy(s[r],ls);
        s1[r]=s1[f]+1;
      }
    }
    f++;
  }
  if (jl==0) printf("No solution!\n");
}
int main()
{
  freopen("act.in","r",stdin);
  freopen("act.out","w",stdout);
  for (i=1;i<=8;i++)
    scanf("%d",&s[0][i]);
  a[cd(s[0])]=1;
  anss[1]=1;anss[2]=2;
  anss[3]=3;anss[4]=4;
  anss[5]=8;anss[6]=7;
  anss[7]=6;anss[8]=5;
  s1[0]=0;
  if (same(s[0],anss)==0) printf("0\n");
  else bfs();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
