#include<stdio.h>
int z,xs,ys,tempx,tempy,sum[10005]={0},x[10000]={0},y[10000]={0},hash[10000][10000]={0};
int check(int i,int x1,int y1)
{
    if(i==1 && x1==0)return 0;
    if(i==2 && y1==0)return 0;
    if(i==3 && x1>=xs)return 0;
    if(i==4 && y1>=ys)return 0;
    if(i==5 && (x1>=xs && y1<=0))return 0;
    if(i==6 && (x1<=0 && y1>=ys))return 0;
    return 1;
}
int change(int i)
{
    int temp;
    if(i==1)tempx=0;
    if(i==2)tempy=0;
    if(i==3)tempx=xs;
    if(i==4)tempy=ys;
    if(i==5)
    {
      temp=tempx+tempy;
      if(temp>xs) 
      {
        tempx=xs; 
        tempy=temp-tempx;
      }
      else
      {
        tempx=temp;
        tempy=temp-tempx;
      }   
    }
    if(i==6)
    {
      temp=tempx+tempy;
      if(temp>ys) 
      {
        tempy=ys; 
        tempx=temp-tempy;
      }
      else
      {
        tempy=temp;
        tempx=temp-tempy;
      }   
    }
}
int main()
{
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
    int i,count=0,now=2;
    scanf("%d%d%d",&xs,&ys,&z);
    x[1]=xs;
    y[1]=0;
    hash[xs][0]=1;
    while(count!=now)
    {
      count++;
      for(i=1;i<=6;i++)
      {
        tempx=x[count];
        tempy=y[count];
        if(check(i,tempx,tempy))
        {
          change(i);
          sum[now]=sum[count]+1;
          if(tempy==z)
          {
            printf("%d",sum[now]);
            fclose(stdin);
            fclose(stdout);
            return 0;
          }
          if(hash[tempx][tempy]==0)
          {
            hash[tempx][tempy]=1;
            x[now]=tempx;
            y[now]=tempy;
            now++;
          }
        }
      }
    }
    printf("No solution!");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
