#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	
	int *a,n;
	clock_t start,end;
	printf("\nPlease enter the size of an array:");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	printf("\nBEST CASE");
	
	for(int i=0;i<n;i++)
	{
		a[i]=i+1;
	}
	start=clock();
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	end=clock();
	printf("Start time=%ld\n",start);
	printf("End time=%ld\n",end);
	double total_cputime=(double)(end-start)/CLOCKS_PER_SEC;
	printf("Total CPU Time in second=%f\n",total_cputime);
	printf("\n");
	printf("\nWORST CASE");
	for(int i=0;i<n;i++)
	{
		a[i]=n-i;
	}
	start=clock();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	end=clock();
	printf("Start time=%ld\n",start);
	printf("End time=%ld\n",end);
	total_cputime=(double)(end-start)/CLOCKS_PER_SEC;
	printf("Total CPU Time in second=%f\n",total_cputime);
	printf("\n");
	printf("FOR AVERAGE CASE\n");
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%n;
	}
	start=clock();
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	end=clock();
	printf("Start time=%ld\n",start);
	printf("End time=%ld\n",end);
	total_cputime=(double)(end-start)/CLOCKS_PER_SEC;
	printf("Total CPU Time in second=%f\n",total_cputime);
	
}