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
	for(int i=0;i<n;i++)
	{
		a[i]=i+1;
	}
	printf("\nFOR BEST CASE");
	start=clock();
	for(int i=0;i<n-1;i++)
	{
		int s=a[i],p=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<s)
			{
				s=a[j];
				p=j;
			}
		}
		int t=a[i];
		a[i]=a[p];
		a[p]=t;
	}
	/*for(int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}*/
	end=clock();
	printf("Start time=%ld\n",start);
	printf("End time=%ld\n",end);
	double total_cputime=(double)(end-start)/CLOCKS_PER_SEC;
	printf("Total CPU Time in second=%f\n",total_cputime);
	printf("\n");
	printf("\nFOR WORST CASE");
	for(int i=0;i<n;i++)
	{
		a[i]=n-i;
	}
	start=clock();
	for(int i=0;i<n-1;i++)
	{
		int s=a[i],p=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<s)
			{
				s=a[j];
				p=j;
			}
		}
		int t=a[i];
		a[i]=a[p];
		a[p]=t;
	}
	end=clock();
	printf("Start time=%ld\n",start);
	printf("End time=%ld\n",end);
	total_cputime=(double)(end-start)/CLOCKS_PER_SEC;
	printf("Total CPU Time in second=%f\n",total_cputime);
	printf("\n");
	printf("\nFOR AVERAGE CASE");
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%n;
	}
	start=clock();
	for(int i=0;i<n-1;i++)
	{
		int s=a[i],p=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<s)
			{
				s=a[j];
				p=j;
			}
		}
		int t=a[i];
		a[i]=a[p];
		a[p]=t;
	}
	end=clock();
	printf("Start time=%ld\n",start);
	printf("End time=%ld\n",end);
	total_cputime=(double)(end-start)/CLOCKS_PER_SEC;
	printf("Total CPU Time in second=%f\n",total_cputime);
	printf("\n");
}