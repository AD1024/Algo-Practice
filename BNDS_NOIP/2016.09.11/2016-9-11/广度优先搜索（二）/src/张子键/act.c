#include <stdio.h>
#include <string.h>

char start[9]="12348765",end[9]="\0",c[100002][9]={"\0"};
int k[100002]={0},behind[100002]={0};
int f[9][9][9][9][9][9][9][9]={0};

void findfather(int i)
{
    if(i<=0) return;
    findfather(behind[i]);
    printf("\n%c %c %c %c\n",c[i][0],c[i][1],c[i][2],c[i][3]);
    printf("%c %c %c %c\n",c[i][4],c[i][5],c[i][6],c[i][7]);
    return;
}

int main()
{
    int l,r,i,j,now;
    freopen("act.in","r",stdin);
    freopen("act.out","w",stdout);
    scanf("%c %c %c %c\n",&end[0],&end[1],&end[2],&end[3]);
    scanf("%c %c %c %c",&end[4],&end[5],&end[6],&end[7]);
    l=1;
    r=2;
    f[end[0]-'0'][end[1]-'0'][end[2]-'0'][end[3]-'0'][end[4]-'0'][end[5]-'0'][end[6]-'0'][end[7]-'0']=1;
    strcpy(c[1],end);
    for(;l<r;)
    {
        if(strcmp(c[l],start)==0)
        {
            printf("%d\n",k[l]);
            fclose(stdin);
            fclose(stdout);
            return 0;
        }
        
        strcpy(c[r],c[l]);
        c[r][0]+=c[r][4]; c[r][4]=c[r][0]-c[r][4]; c[r][0]-=c[r][4];
        c[r][1]+=c[r][5]; c[r][5]=c[r][1]-c[r][5]; c[r][1]-=c[r][5];
        c[r][2]+=c[r][6]; c[r][6]=c[r][2]-c[r][6]; c[r][2]-=c[r][6];
        c[r][3]+=c[r][7]; c[r][7]=c[r][3]-c[r][7]; c[r][3]-=c[r][7];
        if(f[c[r][0]-'0'][c[r][1]-'0'][c[r][2]-'0'][c[r][3]-'0'][c[r][4]-'0'][c[r][5]-'0'][c[r][6]-'0'][c[r][7]-'0']==0)
        {
            f[c[r][0]-'0'][c[r][1]-'0'][c[r][2]-'0'][c[r][3]-'0'][c[r][4]-'0'][c[r][5]-'0'][c[r][6]-'0'][c[r][7]-'0']=1;
            k[r]=k[l]+1; behind[r]=l;
            if(strcmp(c[r],start)==0)
            {
                printf("%d\n",k[l]+1);
        //        findfather(r);
                fclose(stdin);
                fclose(stdout);
                return 0;
            }
            r++;
        }
        
        c[r][0]=c[l][3]; c[r][1]=c[l][0]; c[r][2]=c[l][1]; c[r][3]=c[l][2];
        c[r][4]=c[l][7]; c[r][5]=c[l][4]; c[r][6]=c[l][5]; c[r][7]=c[l][6];
        if(f[c[r][0]-'0'][c[r][1]-'0'][c[r][2]-'0'][c[r][3]-'0'][c[r][4]-'0'][c[r][5]-'0'][c[r][6]-'0'][c[r][7]-'0']==0)
        {
            f[c[r][0]-'0'][c[r][1]-'0'][c[r][2]-'0'][c[r][3]-'0'][c[r][4]-'0'][c[r][5]-'0'][c[r][6]-'0'][c[r][7]-'0']=1;
            k[r]=k[l]+1; behind[r]=l;
            if(strcmp(c[r],start)==0)
            {
                printf("%d\n",k[l]+1);
         //       findfather(r);
                fclose(stdin);
                fclose(stdout);
                return 0;
            }
            r++;
        }
        
        c[r][0]=c[l][0]; c[r][3]=c[l][3]; c[r][4]=c[l][4]; c[r][7]=c[l][7];
        c[r][1]=c[l][5]; c[r][2]=c[l][1]; c[r][5]=c[l][6]; c[r][6]=c[l][2];
        if(f[c[r][0]-'0'][c[r][1]-'0'][c[r][2]-'0'][c[r][3]-'0'][c[r][4]-'0'][c[r][5]-'0'][c[r][6]-'0'][c[r][7]-'0']==0)
        {
            f[c[r][0]-'0'][c[r][1]-'0'][c[r][2]-'0'][c[r][3]-'0'][c[r][4]-'0'][c[r][5]-'0'][c[r][6]-'0'][c[r][7]-'0']=1;
            k[r]=k[l]+1; behind[r]=l;
            if(strcmp(c[r],start)==0)
            {
                printf("%d\n",k[l]+1);
         //       findfather(r);
                fclose(stdin);
                fclose(stdout);
                return 0;
            }
            r++;
        }
        
        l++;
    }
    printf("No solution!\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
