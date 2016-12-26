#include<stdio.h>
int max=-1,m,n,i,j,weight[1005]={0},value[1005]={0},f[1005][1005]={0};
int main()
{

    freopen("bag.in","r",stdin);
    freopen("bag.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
     scanf("%d%d",&weight[i],&value[i]);
    for(i=1,j=1;i<=n;i++)
    {
     for(j=1;j<=m;j++)
     {  
      f[i][j]=f[i-1][j];
      if(j-weight[i]>=0)
        if(f[i][j]<=f[i-1][j-weight[i]]+value[i])
         f[i][j]=f[i-1][j-weight[i]]+value[i];  
     }
    } 
    for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
     {
      if(max<f[i][j])
       max=f[i][j];
     }
    printf("%d ",max);
    fclose(stdin);
    fclose(stdout);
    return 0;
}      
