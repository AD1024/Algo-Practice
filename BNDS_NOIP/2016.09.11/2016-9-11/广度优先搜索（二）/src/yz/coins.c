#include<stdio.h>
int m,n,k,a[1000]={0},b[10000][10000]={0},r=1,f=0,i,j;
int main()
{
    int o;
    freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    a[m]=1;
    b[1][1]=m;b[1][2]=n-m;
    for(o=0;f<r;o++)
    {
     f++;
     for(i=0;i<=k;i++)
      if(b[f][1]-i>=0 && b[f][2]-k+i>=0)
       if(a[b[f][1]+k-2*i]==0)
       {
        a[b[f][1]+k-2*i]=1;
        r++;
        b[r][1]=b[f][1]+k-2*i;
        b[r][2]=b[f][2]-k+2*i;
        b[r][3]=b[f][3]+1;
        if(b[r][1]==0)
        {
         vb();
         f=r+10;
         break;
        }
       }
    }
    if(f!=r+10)
     printf("No solution!");
    fclose(stdin);
    fclose(stdout);
}
int vb()
{
  printf("%d ",b[r][3]);
}
    
