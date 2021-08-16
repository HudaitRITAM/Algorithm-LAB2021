#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int partition (int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main() {

	

	printf("n\t\t|\tworst\t\tavg\t\t\tbest\n__|____\n");

	int sizes;
	scanf("%d",&sizes);

	for(int i=0;i<sizes;i++) {   
		int n;
		scanf("%d", &n);  

		printf("%d\t|\t", n);
		int arr[n];
		time_t start, end;
		double time;

		// Worst
		for(int j=0;j<n;j++) {    
			arr[j] = j + 1;
		}

		start = clock();
		quickSort(arr, 0, n - 1);
		end = clock();

		time = (end - start) * 1.0 / CLOCKS_PER_SEC;

		printf("%f\t", time);

		// Avg
		for(int j=0;j<n;j++) {     
			arr[j] = n - j;
		}

		start = clock();
		quickSort(arr, 0, n - 1);
		end = clock();

		time = (end - start) * 1.0 / CLOCKS_PER_SEC;

		printf("%f\t", time);


		// Best
		for(int j=0;j<n;j++) {   
			arr[j] = rand() % 10000;
		}

		start = clock();
		quickSort(arr, 0, n - 1);
		end = clock();

		time = (end - start) * 1.0 / CLOCKS_PER_SEC;

		printf("%f\n", time);


	}


	return 0;
}