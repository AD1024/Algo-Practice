#include<stdio.h>
struct map
{
     int x,y,step;  
}end,doe,newr,line[10001]={0};

int hash[51][51]={0},f=0,r=0;
int way[4]={0},move[4][2]={{1,2},{2,1},{1,-2},{2,-1}};


int check();
void make_way();
void in()
{
     line[r]=newr;
     r=(r+1)%10001;
     
}

void out()
{
    doe=line[f];
    f=(f+1)%10001; 
}

int BFS()
{
     int i;
     
    while(f!=r)
    {
        out();       
        make_way();
               
        for(i=0;i<4;i++)       
         if(way[i])
       {
          newr=doe;
          newr.x+=move[i][0],newr.y+=move[i][1];
          newr.step++;                        
          
          if(check())
             return  newr.step;
          if(hash[newr.x][newr.y]==0)
             { hash[newr.x][newr.y]=1;  in();   }           
       }
     
    } 
    return -1;
}


int main()
{
    int ans;
    
    freopen("knight.in","r",stdin);
    freopen("knight.out","w",stdout);
    
    scanf("%d%d",&end.x,&end.y);
    
    newr.x=1,newr.y=1,newr.step=0;
    hash[1][1]=1;in();
    
    if(check())
       printf("0");
    else
    {
       ans=BFS();
       if(ans>0)
          printf("%d",ans);  
       else
          printf("No solution!"); 
    }   
    
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
int check()
{
    if(newr.x==end.x && newr.y==end.y)
       return 1;
    
    return 0;
}
void make_way()
{
     int i;
     
     for(i=0;i<4;i++)
      if(doe.x+move[i][0]<=end.x && doe.y+move[i][1]>=1 && doe.y+move[i][1]<=end.y)
        way[i]=1;
      else
        way[i]=0;  
        
}

