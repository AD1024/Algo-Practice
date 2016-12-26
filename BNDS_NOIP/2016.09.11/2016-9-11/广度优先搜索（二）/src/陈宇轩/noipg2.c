#include<stdio.h>
#include<string.h>
char rule[6][60]={'\0'},change[6][60]={'\0'}, gg ;
int lence[6]={0};
char line[10001][60]={'\0'};int f=0,r=0;
int step[10001]={0};
char dream[60]={'\0'};
char doe[60]={'\0'},newr[60]={'\0'};

int check()
{
    if(strcmp(newr,dream)==0)return 1;
    else   return 0;      
}

void p(int start,int a,int len)
{
     int q,end;
     int i,j,k=0;
     q=strlen(change[a]);
     
     for(i=0;i<60;i++)
        newr[i]='\0';
     
     for(i=0;i<start;i++)
        newr[k++]=doe[i];
     
     
     for(i=0;i<q;i++)
        newr[k++]=change[a][i];
        
     end=start+strlen(rule[a]);
     for(i=end;i<len;i++)
        newr[k++]=doe[i];
     
           
     
}

int BFS()
{
    int i,j,k,e,flag,len;
    
    while(f!=r)
    {
         strcpy(doe,line[f]);
         e=step[f];
         f=(f+1)%100001;
         e++;    
                  
         len=strlen(doe);
           
               
      for(i=0;i<gg;i++)
      {

         for(j=0;j<=len-lence[i];j++)
        {  
            flag=1;                        
           for(k=0;k<lence[i];k++)
             if(doe[k+j]!=rule[i][k])
               {flag=0;break;}
           
           if(flag==1)
           {  
              p(j,i,len);
           
             if(check())
              return e;
              
             if(e<10)
             {
              strcpy(line[r],newr);
              step[r]=e;
              r=(r+1)%10001;
              }
           }
        
           
        }    
         
         
             
      }
         
          for(i=0;i<len;i++)
            doe[i]='\0';
    }
    
    return -1;
}

int main()
{
    int i,ans;
    
    freopen("noipg2.in","r",stdin);
    freopen("noipg2.out","w",stdout);
    
    scanf("%s",newr);
    strcpy(line[0],newr);
    step[0]=0;
    r++;
    
    scanf("%s",dream);
    
    i=0;
    while(scanf("%s",rule[i])!=EOF)
    {
      lence[i]=strlen(rule[i]);
      scanf("%s",change[i++]);
    }
    gg=i;
    
      
    if(check())
       printf("0");
    else
    {
       ans=BFS(); 
        if(ans>0)
           printf("%d",ans);
        else
           printf("NO ANSWER!");   
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
