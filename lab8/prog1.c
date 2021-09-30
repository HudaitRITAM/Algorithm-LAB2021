#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void heapify(int *arr, int n, int i)
{

	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(arr + i, arr + largest);

		heapify(arr, n, largest);
	}
}


void heapSort(int *arr, int n) {

	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(arr + 0, arr + i);
		heapify(arr, i, 0);
	}

}


int main() {
	printf("n\t\t|\tTime Taken\n___|____\n\t\t|\n");

	int sizes;
	scanf("%d",&sizes);

	for(int i=0;i<sizes;i++) {
		int n;
		scanf("%d",&n);

		printf("%d\t|\t", n);
		int arr[n];
		time_t start, end;
		double time;
		for(int j=0;j<n;j++) {
			arr[j] = rand() % 100000;
		}

		start = clock();
		heapSort(arr, n);
		end = clock();
		time = (end - start) * 1.0 / CLOCKS_PER_SEC;
		printf("%f\n", time);

	}

	printf("\nComplexity: nlog(n) for all the three cases.\n");

	return 0;
}