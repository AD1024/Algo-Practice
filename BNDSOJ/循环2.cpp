#include<iostream>
using namespace std;
char s[200];
int k,ans[110];
void x(int a[],int b[],int b1,int c[],int c1){
   int i,j;
   for(i=0;i<c1;i++) c[i]=0;
   if(b1>c1) b1=c1;
   for(i=0;i<b1;i++){   
       if(b[i])
           for(j=0;j<c1-i;j++){
               c[i+j]=a[j]*b[i]+c[i+j];
               c[i+j+1]=c[i+j+1]+c[j+i]/10;
               c[i+j]=c[i+j]%10;
            }
    }
}
int a[110],b[110],c[110],d[110],i,j,num,n,p;
int main()
{
    cin>>s>>k;
    n=strlen(s);
    for(i=0;i<n;i++) a[n-i-1]=s[i]-'0';
    for(i=0;i<k;i++) d[i]=a[i];
    ans[0]=1;
    for(i=0;i<k;i++)
    {
         for(j=0;j<=i;j++) b[j]=d[j];         
         p=b[i];
         num=0;
         do
         {
              x(a,b,i+1,c,i+1);
              num++;
              for(n=0;n<k;n++) b[n]=c[n];
         } while((num<10)&&(b[i]!=p));
         if(b[i]!=p) 
         { 
            cout<<-1<<endl;
            return 0;
         }
         for(j=0;j<k;j++) b[j]=a[j];
         for(j=0;j<num-1;j++)
         {
             x(a,b,k,c,k);
             for(n=0;n<110;n++) a[n]=c[n];
         }
         x(ans,&num,1,c,110);
         for(n=0;n<110;n++) ans[n]=c[n];
     }
     for(i=110-1;ans[i]==0;i--);   
     for(;i>=0;i--) cout<<ans[i];
}