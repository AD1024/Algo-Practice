#include <stdio.h>
#include <string.h>

char g[7][3][22]={"\0"};
char start[22]="\0",end[22]="\0";
char c[10000002][22]={"\0"};
int k[10000002]={0};
int behind[10000002]={0};

int main()
{
    int i,j,l,r,n,f,p,x=0;
    char a[22]="\0",b[22]="\0";
    freopen("noipg2.in","r",stdin);
    freopen("noipg2.out","w",stdout);
    scanf("%s",start);
    scanf("%s",end);
    for(i=1;scanf("%s%s",g[i][0],g[i][1])!=EOF;i++);
    n=i-1;
    l=1;
    r=2;
    strcpy(c[1],start);
    for(;l<r;)
    {
        if(k[l]>=10) break;
        for(i=1;i<=n;i++)
        {
            for(f=0;f<strlen(c[l]);f++)
            {
                x=0;
                for(p=0;p<strlen(g[i][0]);p++)
                    if(c[l][f+p]!=g[i][0][p])
                        x=1;
                if(x==1) continue;
                strcpy(a,b);
                strcpy(c[r],c[l]);
                c[r][f]='\0';
                strcat(c[r],g[i][1]);
                for(j=f+strlen(g[i][0]);j<strlen(c[l]);j++)
                {
                    a[j-f-strlen(g[i][0])]=c[l][j];
                    a[j-f-strlen(g[i][0])+1]='\0';
                }
                strcat(c[r],a);
                k[r]=k[l]+1;
                if(strcmp(c[r],end)==0)
                {
                    printf("%d",k[r]);
                    fclose(stdin);
                    fclose(stdout);
                    return 0;
                }
                r++;
            }
        }
        l++;
    }
    printf("NO ANSWER!");
    fclose(stdin);
    fclose(stdout);
    return 0;
}

