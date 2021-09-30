#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for(int i=0;i<n1;i++) {  
		L[i] = arr[l + i];
	}
	for(int i=0;i<n2;i++) {

		R[i] = arr[m + 1 + i];
	}

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}



int main() {

	printf("n\t\t|\tbest\t\tavg\t\t\tworst\n__|____\n");

	int sizes;
	scanf("%d",&sizes);

	for(int i=0;i<sizes;i++) {         
		int n;
		scanf("%d",&n);

		printf("%d\t|\t", n);
		int arr[n];
		time_t start, end;
		double time;

		// Best
		for(int j=0;j<n;j++) {
			arr[j] = j + 1;
		}

		start = clock();
		mergeSort(arr, 0, n - 1);
		end = clock();

		time = (end - start) * 1.0 / CLOCKS_PER_SEC;

		printf("%f\t", time);

		// Avg
		for(int j=0;j<n;j++) {
			arr[j] = rand() % 10000;
		}

		start = clock();
		mergeSort(arr, 0, n - 1);
		end = clock();

		time = (end - start) * 1.0 / CLOCKS_PER_SEC;

		printf("%f\t", time);


		// Worst
		for(int j=0;j<n;j++) {
			arr[j] = rand() % 10000;
		}

		start = clock();
		mergeSort(arr, 0, n - 1);
		end = clock();

		time = (end - start) * 1.0 / CLOCKS_PER_SEC;

		printf("%f\n", time);

	}

	return 0;
}