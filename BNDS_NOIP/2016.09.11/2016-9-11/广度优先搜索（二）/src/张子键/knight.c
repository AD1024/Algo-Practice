#include <stdio.h>
int d[100002][2]={0},k[100002]={0},behind[100002]={0};
int f[52][52]={0};

void findfather(int i)
{
    if(i<=0) return;
    findfather(behind[i]);
    printf("\n%d %d\n",d[i][0],d[i][1]);
    return;
}

int main()
{
    int n,m,l,r;
    freopen("knight.in","r",stdin);
    freopen("knight.out","w",stdout);
    scanf("%d%d",&n,&m);
    l=1;
    r=2;
    d[1][0]=1;
    d[1][1]=1;
    f[1][1]=1;
    for(;l<r;)
    {
        if(d[l][0]+2<=n)
        {
            if(d[l][1]+1<=m && f[d[l][0]+2][d[l][1]+1]==0)
            {
                f[d[l][0]+2][d[l][1]+1]=1;
                d[r][0]=d[l][0]+2;
                d[r][1]=d[l][1]+1;
                k[r]=k[l]+1;
                behind[r]=l;
                if(d[r][0]==n && d[r][1]==m)
                {
                    printf("%d\n",k[r]);
              //      findfather(r);
                    fclose(stdin);
                    fclose(stdout);
                    return 0;
                }
                r++;
            }
            if(d[l][1]-1>=1 && f[d[l][0]+2][d[l][1]-1]==0)
            {
                f[d[l][0]+2][d[l][1]-1]=1;
                d[r][0]=d[l][0]+2;
                d[r][1]=d[l][1]-1;
                k[r]=k[l]+1;
                behind[r]=l;
                if(d[r][0]==n && d[r][1]==m)
                {
                    printf("%d\n",k[r]);
             //       findfather(r);
                    fclose(stdin);
                    fclose(stdout);
                    return 0;
                }
                r++;
            }
        }
        if(d[l][0]+1<=n)
        {
            if(d[l][1]+2<=m && f[d[l][0]+1][d[l][1]+2]==0)
            {
                f[d[l][0]+1][d[l][1]+2]=1;
                d[r][0]=d[l][0]+1;
                d[r][1]=d[l][1]+2;
                k[r]=k[l]+1;
                behind[r]=l;
                if(d[r][0]==n && d[r][1]==m)
                {
                    printf("%d\n",k[r]);
             //       findfather(r);
                    fclose(stdin);
                    fclose(stdout);
                    return 0;
                }
                r++;
            }
            if(d[l][1]-2>=1 && f[d[l][0]+1][d[l][1]-2]==0)
            {
                f[d[l][0]+1][d[l][1]-2]=1;
                d[r][0]=d[l][0]+1;
                d[r][1]=d[l][1]-2;
                k[r]=k[l]+1;
                behind[r]=l;
                if(d[r][0]==n && d[r][1]==m)
                {
                    printf("%d\n",k[r]);
              //      findfather(r);
                    fclose(stdin);
                    fclose(stdout);
                    return 0;
                }
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
