#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>

int maxDiff(int a[], int n)
{
	int max = INT_MIN, c;

	for(int i=0;i<n;i++) {
		for(int j=i + 1;j<n;j++) {
			c = a[j] - a[i];

			max = (c > max) ? c : max;

		}
	}

	return max;
}



int main() {


	int n;
	scanf("%d",&n);

	int arr[n];
	for(int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}

	time_t start, end;
	double time;
	start = clock();
	printf("Max Difference : %d\n", maxDiff(arr, n));
	end = clock();

	time = (end - start) * 1.0 / CLOCKS_PER_SEC;

	printf("Time taken: %f seconds", time);





	return 0;
}