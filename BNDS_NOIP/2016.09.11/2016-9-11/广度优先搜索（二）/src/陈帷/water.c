#include<stdio.h>
#include<stdlib.h>
int a[10001][2]={{0}},x,y,z,ans[10001]={0},f=0,r=1,h[101][101]={{0}},p=0;
void bh(int c,int xx,int yy)
{//0:xx->0;1:xx->yy;2:xx->x;3:yy->0;4:yy->xx;5:yy->y;
     int o=0;
     switch(c)
              {
                  case 0:xx=0;break; 
                  case 1:if(xx<y)yy+=(xx-yy),xx=0;else{xx-=(y-yy),yy=y;}break; 
                  case 2:xx=x;break; 
                  case 3:yy=0;break; 
                  case 4:if(yy<x)xx+=(yy-xx),yy=0;else{yy-=(x-xx),xx=x;}break; 
                  case 5:yy=y;break; 
              }
     if(h[xx][yy]==0&&xx>=0&&yy>=0&&xx<=x&&yy<=y)
     {
       h[xx][yy]=1;
       if(yy==z)
       {
         p=1;
         printf("%d",ans[r-1]+1);
         return;
       }
       else
       {
         ans[r]+=ans[f-1]+1;
         a[r][0]=xx;
         a[r][1]=yy;
         r++;
       }
     }
}
int pd(int c,int xx,int yy)
{//0:xx->0;1:xx->yy;2:xx->x;3:yy->0;4:yy->xx;5:yy->y;
     if(c==0&&xx>0)return 1;
     else if(c==1&&xx>0&&yy<y)return 1;
     else if(c==2&&xx<x)return 1;
     else if(c==3&&yy>0)return 1;
     else if(c==4&&yy>0&&xx<x)return 1;
     else if(c==5&&yy<y)return 1;
     return 0;
}
void qwe()
{
     int c,xx,yy;
     do
     {
         xx=a[f][0];
         yy=a[f][1];
         f++;
         for(c=0;c<6;c++)
           if(pd(c,xx,yy))
             bh(c,xx,yy);
     }while(f<=r&&ans[r-1]<=3000);
}
int main()
{
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
    scanf("%d%d%d",&x,&y,&z);
    a[0][0]=x;
    h[x][0]=1;
    qwe();
    if(p==0)
      printf("No solution!");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
