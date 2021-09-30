#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define pfs(x)             printf("%d ", x)

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

int extract_maximum(int *arr, int n) {

	int m = *arr;

	arr[0] = arr[n - 1];

	heapify(arr, n - 1, 0);

	return m;
}

int kthMax(int *arr, int n, int k) {

	int ans = 0;

	for(int i=0;i<k;i++) {
		ans = extract_maximum(arr, n);
		n--;
	}

	return ans;

}
int main() {
	printf("n\t\t|\tElement |\tTime\n___|___|_____\n");

	int sizes;
	scanf("%d",&sizes);

	for(int i=0;i<sizes;i++) {
		int n;
		scanf("%d",&n);

		printf("%d\t|\t", n);
		int arr[n];
		for(int j=0;j<n;j++) {
			arr[j] = 1 + j;
		}

		buildHeap(arr, n);

		time_t start, end;
		double time;

		// Time

		start = clock();
		pfs(kthMax(arr, n, 5));
		printf("\t|\t");
		end = clock();

		time = (end - start) * 1.0 / CLOCKS_PER_SEC;

		printf("%f\n", time);

	}

	return 0;
}