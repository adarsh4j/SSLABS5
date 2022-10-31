#include<stdio.h>
#include<stdlib.h>
void main()
{
   int f[50],str=0,len,i,j,c,k,count=0;
   for(i=0;i<50;i++){
     f[i]=0;}
   printf("File alocated are:\n");
   x:count=0;
   printf("Enter the starting block and length of file:");
   scanf("%d %d",&str,&len);
   for(k=str;k<(str+len);k++){
      if(f[k]==0)
      {
         count++;
      }
   }
   if(len==count)
   {
     for(j=str;j<(str+len);j++)
     {
       if(f[j]==0)
       {
          f[j]=1;
          printf("%d\t%d\n",j,f[j]);
       }
     }
     if(j!=(str+len-1))
       printf("The file is allocated to disk\n");
   }
   else
   {
      printf("The file is not allocated to disk\n");
      printf("Do you want to enter more files(YES-1/NO-0)");
      scanf("%d",&c);
      if(c==1)
      goto x;
   }
}


 
   









     
     
