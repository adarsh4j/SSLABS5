#include<stdio.h>
#include<stdlib.h>

void scanALG(int [],int,int);

void main()
{
	int n,i,intialhead,ch;
	printf("Enter the number of requests : ");
	scanf("%d",&n);
	int req[n];
	printf("Enter the sequence : ");
	for(i=0;i<n;i++)
		scanf("%d",&req[i]);
	printf("Enter the intial head : ");
	scanf("%d",&intialhead);
	scanALG(req,intialhead,n);
}
void scanALG(int r[], int intial, int n)
{
	int disksize,d,i,j,total;
	printf("Enter the disk size :");
	scanf("%d",&disksize);
	printf("Enter the head movement direction 1. High\t2.Low");
	scanf("%d",&d);
	//Sort the req arrey
	for(i=0;i<n;i++)
	{
		for( j=0;j<n-i-1;j++)
		{
			if(r[j]>r[j+1])
			{
				int temp;
				temp=r[j];
				r[j]=r[j+1];
				r[j+1]=temp;
			}
			
		}
	}
	int index;
	for(i=0;i<n;i++)
	{
		if(intial<r[i])
		{
			index=i;
			break;
		}
	}
	if(d==1)
	{
		for(i=index;i<n;i++)
		{
			total=total+abs(r[i]-intial);
			intial=r[i];
		}
		//  last movement for max size 
		total=total+abs(disksize-r[i-1]-1);
		intial = disksize-1;
		for(i=index-1;i>=0;i--)
		{
			total=total+abs(r[i]-intial);
			intial=r[i];
			
		}
	}
	// if movement is towards low value
	else
	{
		for(i=index-1;i>=0;i--)
		{
			total=total+abs(r[i]-intial);
			intial=r[i];
		}
		//  last movement for min size 
		total=total+abs(r[i+1]-0);
		intial =0;
		for(i=index;i<n;i++)
		{
			total=total+abs(r[i]-intial);
			intial=r[i];
			
		}
	}
	
	printf("Total head movement is %d",total);
}
