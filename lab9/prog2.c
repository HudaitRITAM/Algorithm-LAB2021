#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define pfs(x)             printf("%d ", x)

int binSearch(int *a, int s, int e, int x) {

	if (s > e) {
		return -1;
	}

	int m = (s + e) / 2;

	if (a[m] == x)
		return m;

	if (a[m] > x)
		return binSearch(a, s, m - 1, x);

	if (a[m] < x)
		return binSearch(a, m + 1, e, x);

}

int main() {
	printf("n\t\t|\tworst\t\t\tavg\t\t\t\tbest\n___|________________\n");
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
		time_t start, end;
		double time;

		// Worst

		start = clock();
		pfs(binSearch(arr, 0, n - 1, 1)); 
		end = clock();

		time = (end - start) * 1.0 / CLOCKS_PER_SEC;

		printf("%f\t", time);
		// Avg
		start = clock();
		pfs(binSearch(arr, 0, n - 1, 1000));
		end = clock();

		time = (end - start) * 1.0 / CLOCKS_PER_SEC;

		printf("%f\t", time);

		// Best

		start = clock();
		pfs(binSearch(arr, 0, n - 1, (n - 1) / 2));
		end = clock();

		time = (end - start) * 1.0 / CLOCKS_PER_SEC;

		printf("%f\n", time);
	}

	return 0;
}
