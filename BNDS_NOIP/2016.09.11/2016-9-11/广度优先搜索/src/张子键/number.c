#include <stdio.h>
#include <string.h>
char start[11]="\0",end[11]="\0",f[876543213]={0};
char c[200002][11]={"\0"},b='\0';

int main()
{
    int l,r,i,j,x=0,k[200002]={0},num;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%c %c %c\n",&start[0],&start[1],&start[2]);
    scanf("%c %c %c\n",&start[3],&start[4],&start[5]);
    scanf("%c %c %c\n",&start[6],&start[7],&start[8]);
    for(i=0;i<=8;i++)
        if(start[i]=='0')
        {
            start[9]=i+'0';
            break;
        }
    scanf("%c %c %c\n",&end[0],&end[1],&end[2]);
    scanf("%c %c %c\n",&end[3],&end[4],&end[5]);
    scanf("%c %c %c\n",&end[6],&end[7],&end[8]);
    for(i=0;i<=8;i++)
        if(end[i]=='0')
        {
            end[9]=i+'0';
            break;
        }
    strcpy(c[1],start);
    l=1;
    r=2;
    num=(start[0]-'0')*100000000+(start[1]-'0')*10000000+(start[2]-'0')*1000000+(start[3]-'0')*100000+(start[4]-'0')*10000+(start[5]-'0')*1000+(start[6]-'0')*100+(start[7]-'0')*10+(start[8]-'0');
    f[num]=1;
    for(;k[l]<=40;)
    {
        if(l>=r) break;
        if(strcmp(c[l],end)==0)
        {
            x=1;
            i=k[l];
            break;
        }
        else
        {
            if(c[l][9]-3-'0'>=0)
            {
                strcpy(c[r],c[l]);
                b=c[r][c[r][9]-'0'];
                c[r][c[r][9]-'0']=c[r][c[r][9]-3-'0'];
                c[r][c[r][9]-3-'0']=b;
                c[r][9]=c[r][9]-3;
                if(strcmp(c[r],end)==0)
                {
                    x=1;
                    i=k[l]+1;
                    break;
                }
                num=(c[r][0]-'0')*100000000+(c[r][1]-'0')*10000000+(c[r][2]-'0')*1000000+(c[r][3]-'0')*100000+(c[r][4]-'0')*10000+(c[r][5]-'0')*1000+(c[r][6]-'0')*100+(c[r][7]-'0')*10+(c[r][8]-'0');
                if(f[num]==0)
                {
                    k[r]=k[l]+1;
                    r++;
                    f[num]=1;
                }
            }
            if(c[l][9]+3-'0'<=8)
            {
                strcpy(c[r],c[l]);
                b=c[r][c[r][9]-'0'];
                c[r][c[r][9]-'0']=c[r][c[r][9]+3-'0'];
                c[r][c[r][9]+3-'0']=b;
                c[r][9]=c[r][9]+3;
                if(strcmp(c[r],end)==0)
                {
                    x=1;
                    i=k[l]+1;
                    break;
                }
                num=(c[r][0]-'0')*100000000+(c[r][1]-'0')*10000000+(c[r][2]-'0')*1000000+(c[r][3]-'0')*100000+(c[r][4]-'0')*10000+(c[r][5]-'0')*1000+(c[r][6]-'0')*100+(c[r][7]-'0')*10+(c[r][8]-'0');
                if(f[num]==0)
                {
                    k[r]=k[l]+1;
                    r++;
                    f[num]=1;
                }
            }
            if((c[l][9]-'0')%3!=0)
            {
                strcpy(c[r],c[l]);
                b=c[r][c[r][9]-'0'];
                c[r][c[r][9]-'0']=c[r][c[r][9]-1-'0'];
                c[r][c[r][9]-1-'0']=b;
                c[r][9]=c[r][9]-1;
                if(strcmp(c[r],end)==0)
                {
                    x=1;
                    i=k[l]+1;
                    break;
                }
                num=(c[r][0]-'0')*100000000+(c[r][1]-'0')*10000000+(c[r][2]-'0')*1000000+(c[r][3]-'0')*100000+(c[r][4]-'0')*10000+(c[r][5]-'0')*1000+(c[r][6]-'0')*100+(c[r][7]-'0')*10+(c[r][8]-'0');
                if(f[num]==0)
                {
                    k[r]=k[l]+1;
                    r++;
                    f[num]=1;
                }
            }
            if((c[l][9]-'0')%3!=2)
            {
                strcpy(c[r],c[l]);
                b=c[r][c[r][9]-'0'];
                c[r][c[r][9]-'0']=c[r][c[r][9]+1-'0'];
                c[r][c[r][9]+1-'0']=b;
                c[r][9]=c[r][9]+1;
                if(strcmp(c[r],end)==0)
                {
                    x=1;
                    i=k[l]+1;
                    break;
                }
                num=(c[r][0]-'0')*100000000+(c[r][1]-'0')*10000000+(c[r][2]-'0')*1000000+(c[r][3]-'0')*100000+(c[r][4]-'0')*10000+(c[r][5]-'0')*1000+(c[r][6]-'0')*100+(c[r][7]-'0')*10+(c[r][8]-'0');
                if(f[num]==0)
                {
                    k[r]=k[l]+1;
                    r++;
                    f[num]=1;
                }
            }
            l++;
        }
    }
    if(x==1)
        printf("%d",i);
    else printf("-1");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
