#include<stdio.h>
#include<stdlib.h>

void cscanALG(int [],int,int);

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
	cscanALG(req,intialhead,n);
}

void cscanALG(int q[], int intial, int n)
{
	int disksize,d,i,j,total2;
	printf("Enter the disk size :");
	scanf("%d",&disksize);
	printf("Enter the head movement direction 1. High\t2.Low");
	scanf("%d",&d);
	//Sort the req arrey
	for(i=0;i<n;i++)
	{
		for( j=0;j<n-i-1;j++)
		{
			if(q[j]>q[j+1])
			{
				int temp;
				temp=q[j];
				q[j]=q[j+1];
				q[j+1]=temp;
			}
			
		}
	}
	//Finding index
	int index;
	for(i=0;i<n;i++)
	{
		if(intial<q[i])
		{
			index=i;
			break;
		}
	}
	
	//if high
	if(d==1)
	{
		for(i=index;i<n;i++)
		{
			total2=total2+abs(q[i]-intial);
			intial=q[i];
		}
		//  last movement for max size 
		total2=total2+abs(disksize-q[i-1]-1);
		/*movement max to min disk */
		total2=total2+abs(disksize-1-0);
		intial=0;
		for( i=0;i<index;i++)
		{
			total2=total2+abs(q[i]-intial);
			intial=q[i];
		}
	}
	else
	{
		for(i=index-1;i>=0;i--)
		{
			total2=total2+abs(q[i]-intial);
			intial=q[i];
		}
		//  last movement for min size 
		total2=total2+abs(q[i+1]-0);
		// movement min to max disk 
		total2=total2+abs(disksize-1-0);
		intial =disksize-1;
		for(i=n-1;i>=index;i--)
		{
			total2=total2+abs(q[i]-intial);
			intial=q[i];
			
		}
	}
	printf("Total Head movement = %d", total2);
}
