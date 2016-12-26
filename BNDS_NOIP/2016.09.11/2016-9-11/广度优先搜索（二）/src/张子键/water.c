#include <stdio.h>
int x,y,z,f[103][103]={0},d[1000002][2]={0},k[1000002]={0};
int behind[1000002]={0};
void findfather(int i)
{
    if(i<=0) return;
    findfather(behind[i]);
    
    if(i>1)
    {
        if(d[behind[i]][0]>d[i][0] && d[behind[i]][1]<d[i][1])
            printf("1->2\n");
        if(d[behind[i]][0]<d[i][0] && d[behind[i]][1]>d[i][1])
            printf("1<-2\n");
        if(d[behind[i]][0]==d[i][0] && d[i][1]==0)
            printf("½«2µ¹¿Õ\n");
        if(d[behind[i]][0]==d[i][0] && d[i][1]==y)
            printf("½«2¹àÂú\n");
        if(d[i][0]==0 && d[behind[i]][1]==d[i][1])
            printf("½«1µ¹¿Õ\n");
        if(d[i][0]==x && d[behind[i]][1]==d[i][1])
            printf("½«1¹àÂú\n");
    }
    printf("%d %d\n",d[i][0],d[i][1]);
    return;
}

int main()
{
    int i,j,l,r;
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
    scanf("%d%d%d",&x,&y,&z);
    f[x][0]=1;
    l=1;
    r=2;
    d[1][0]=x;
    d[1][1]=0;
    for(;l<=r;)
    {
        if(d[l][0]<x && f[x][d[l][1]]==0)
        {
            f[x][d[l][1]]=1;
            d[r][0]=x;
            d[r][1]=d[l][1];
            k[r]=k[l]+1;
            behind[r]=l;
            r++;
        }
        
        if(d[l][1]<y && f[d[l][0]][y]==0)
        {
            f[d[l][0]][y]=1;
            d[r][0]=d[l][0];
            d[r][1]=y;
            k[r]=k[l]+1;
            behind[r]=l;
            r++;
        }
        
        if(d[l][0]>0 && f[0][d[l][1]]==0)
        {
            f[0][d[l][1]]=1;
            d[r][0]=0;
            d[r][1]=d[l][1];
            k[r]=k[l]+1;
            behind[r]=l;
            r++;
        }
        
        if(d[l][1]>0 && f[d[l][0]][0]==0)
        {
            f[d[l][0]][0]=1;
            d[r][0]=d[l][0];
            d[r][1]=0;
            k[r]=k[l]+1;
            behind[r]=l;
            r++;
        }
        
        if(d[l][0]!=x)
        {
            d[r][0]=d[l][0];
            d[r][1]=d[l][1];
            d[r][0]=x;
            d[r][1]-=x-d[l][0];
            if(d[r][1]<0)
            {
                d[r][0]-=-d[r][1];
                d[r][1]=0;
            }
            if(d[r][1]==z)
            {
                k[r]=k[l]+1;
                behind[r]=l;
                printf("%d\n",k[l]+1);
        //        findfather(r);
                fclose(stdin);
                fclose(stdout);
                return 0;
            }
            if(f[d[r][0]][d[r][1]]==0)
            {
                f[d[r][0]][d[r][1]]=1;
                k[r]=k[l]+1;
                behind[r]=l;
                r++;
            }
        }
        
        if(d[l][1]!=y)
        {
            d[r][0]=d[l][0];
            d[r][1]=d[l][1];
            d[r][1]=y;
            d[r][0]-=y-d[l][1];
            
            if(d[r][0]<0)
            {
                d[r][1]-=-d[r][0];
                d[r][0]=0;
            }
            if(d[r][1]==z)
            {
                k[r]=k[l]+1;
                behind[r]=l;
                printf("%d\n",k[l]+1);
           //     findfather(r);
                fclose(stdin);
                fclose(stdout);
                return 0;
            }
            if(f[d[r][0]][d[r][1]]==0)
            {
                f[d[r][0]][d[r][1]]=1;
                k[r]=k[l]+1;
                behind[r]=l;
                r++;
            }
        }
        
        l++;
    }
    printf("No solution!\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
