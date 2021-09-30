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

void buildHeap(int *arr, int n)
{
	int startIdx = (n / 2) - 1;

	for (int i = startIdx; i >= 0; i--) {
		heapify(arr, n, i);
	}
}
int maximum(int *arr, int n) {
	return *arr;
}

int extract_maximum(int *arr, int n) {

	int m = *arr;

	arr[0] = arr[n - 1];

	heapify(arr, n - 1, 0);

	return m;
}

void increase_val(int *arr, int i , int val, int n) {

	arr[i] = val;
	buildHeap(arr, n);

}

void insert_val(int *arr, int n, int val)
{
	n++;
	arr[n - 1] = val;

	heapify(arr, n, n - 1);
}

int main() {
	int n;
	scanf("%d",&n);

	// Constructing
	printf("Constructing MAX heap      : ");
	int arr[n];
	time_t start, end;
	double time;

	for(int j=0;j<n;j++) {
		arr[j] = rand() % 100000;
	}

	start = clock();
	buildHeap(arr, n);
	end = clock();

	time = (end - start) * 1.0 / CLOCKS_PER_SEC;

	printf("%f\n", time);
	printf("Complexity: nlog(n)\n\n");

	// Max of heap
	printf("Finding max element of heap: ");
	start = clock();
	int m = maximum(arr, n);
	end = clock();
	time = (end - start) * 1.0 / CLOCKS_PER_SEC;

	printf("%f\n", time);
	printf("Max element: %d\n", m);
	printf("Complexity: 1\n\n");

	// Max of heap
	printf("Finding max element of heap: ");
	start = clock();
	m = extract_maximum(arr, n);
	n--;
	end = clock();
	time = (end - start) * 1.0 / CLOCKS_PER_SEC;

	printf("%f\n", time);
	printf("Max element: %d\n", m);
	printf("Complexity: log(n)\n\n");

	// Increase val at i of heap
	printf("Increasing val at i of heap: ");
	start = clock();
	increase_val(arr, 5, 9999999, n);
	end = clock();
	time = (end - start) * 1.0 / CLOCKS_PER_SEC;

	printf("%f\n", time);
	printf("Complexity: nlog(n)\n\n");

	// Insert val in heap
	printf("Insertion in heap          : ");
	start = clock();
	insert_val(arr, n, 9999998);
	n++;
	end = clock();
	time = (end - start) * 1.0 / CLOCKS_PER_SEC;

	printf("%f\n", time);
	printf("Complexity: log(n)\n\n");

	return 0;
}